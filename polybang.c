//
//  polybang.c
//  PolyBang
//
//  Created by hdez on 7/8/16.
//  Copyright © 2016 hdez. All rights reserved.
//

//Get the Pure Data headers from: https://github.com/pure-data/pure-data/blob/master/src/m_pd.h
#include "m_pd.h"

//Create a static pointer to the class; it will be initialized in the _setup() method
static t_class *polybang_class;

//Carve out memory for the class data model and typdef it
typedef struct _polybang {
    t_object    x_obj;
    t_int       init_count, current_count;
    t_int       mod_A, mod_B;
    t_inlet     *in_mod_A, *in_mod_B;
    t_outlet    *out_A, *out_B, *out_synch, *out_count;
} t_polybang;

//Set the ratio (A:B)
void polybang_setMods(t_polybang *x, t_floatarg f1, t_floatarg f2){
    //Ensure no negative numbers or 0s are received
    //A
    x->mod_A = (f1 <= 0) ? 1 : f1;
    //B
    x->mod_B = (f2 <= 0) ? 1 : f2;
}

//Reset the count to start at 0
void polybang_resetCount(t_polybang *x){
    //Initialize the counts to start at 0 again
    x->init_count = 0;
    x->current_count = x->init_count;
}

//Perform on bang
void polybang_onBangMsg(t_polybang *x){
    //Create local vars for convenience
    t_int mod_A  = x->mod_A;
    t_int mod_B   = x->mod_B;
    t_int mod_synch = mod_A * mod_B;
    t_int n       = x->current_count;
    
    //Bangs
    if(n % mod_synch == 0){
        //Bangs will be synched when the current count % (A*B) == 0
        //On synch, bang all outputs and reset the current count
        outlet_bang(x->out_A);
        outlet_bang(x->out_B);
        outlet_bang(x->out_synch);
        
        //Reset the count
        x->current_count = 0;
    } else {
        // the current count % A == 0 will cause a bang to out_B
        if(n % mod_A == 0) outlet_bang(x->out_A);
        
        //Same as above but with B
        if(n % mod_B == 0) outlet_bang(x->out_B);
    }
    
    //Always output the current count
    outlet_float(x->out_count, x->current_count);
    
    //Increment the current count
    x->current_count++;
}

void polybang_onResetMsg(t_polybang *x){
    polybang_resetCount(x);
}

//Handle lists: [A B(
void polybang_onListMsg(t_polybang *x, t_symbol *s, t_int argc, t_atom *argv){
    switch(argc){
            //Lists must have two arguments (to set both A and B); otherwise we'll throw an error
        case 2:
            //Set mod_A and mod_B
            polybang_setMods(x, atom_getfloat(argv), atom_getfloat(argv+1));
            
            //Reset the counts
            polybang_resetCount(x);
            break;
        default:
            error("[polybang ]: two arguments are needed to set a new ratio");
    }
}

//Set A part of ratio; however, don't reset
void polybang_onSet_A(t_polybang *x, t_floatarg f){
    //New number for A of A:B
    polybang_setMods(x, f, x->mod_B);
}

//Set B part of ratio; however, don't reset
void polybang_onSetB(t_polybang *x, t_floatarg f){
    //New number for B of A:B
    polybang_setMods(x, x->mod_A, f);
}

//The _new method is a class constructor
//It is required to be named [filename]_new()
void *polybang_new(t_floatarg f1, t_floatarg f2){
    //Create an instance of the polybang class
    t_polybang *x = (t_polybang *)pd_new(polybang_class);
    
    //Initialize the counts
    //Since we'll be doing this in a few different locations, we'll create a method to accomplish this
    polybang_resetCount(x);
    
    //Initialize the mods (e.g. num % mod_A)
    //Since we'll be doing this in a few different locations, we'll create a method to accomplish this
    polybang_setMods(x, f1, f2);

    //Create inlets
    //The left-most inlet is created and destroyed automatically
    //Any additional inlets needed must be explicilty created
    //Inlets are created from left to right on the object
    //Handles (pointers, really) are stored so that we can free them later
    x->in_mod_A = inlet_new(&x->x_obj, &x->x_obj.ob_pd, &s_float, gensym("ratio_A"));
    x->in_mod_B = inlet_new(&x->x_obj, &x->x_obj.ob_pd, &s_float, gensym("ratio_B"));

    //Create outlets
    //Unlike the first inlet, the first isn' created automatically
    //Any outlets needed must be explicitly created
    //Outlets are created from left to right on the object
    //Handles (pointers, really) are stored so that we can send data to the outlets and/or free them later
    x->out_A = outlet_new(&x->x_obj, &s_bang);
    x->out_B = outlet_new(&x->x_obj, &s_bang);
    x->out_synch = outlet_new(&x->x_obj, &s_bang);
    x->out_count = outlet_new(&x->x_obj, &s_float);
      
    //Return the instance
    return (void *)x;
}

void polybang_free(t_polybang *x){
    //If we create any inlets or outlets ourselves, we need to free them to avoid memory leaks
    inlet_free(x->in_mod_A);
    inlet_free(x->in_mod_B);
    outlet_free(x->out_A);
    outlet_free(x->out_B);
    outlet_free(x->out_synch);
    outlet_free(x->out_count);
}

//The _setup method initializes the class in memory
//This method is the place where class behaviors are added
//It is required to be named [filename]_setup()
void polybang_setup(void){
    //Initialize the class
    polybang_class = class_new(gensym("polybang"),
                               (t_newmethod)polybang_new,
                               (t_method)polybang_free,
                               sizeof(t_polybang),
                               CLASS_DEFAULT,
                               A_DEFFLOAT, //A of A:B
                               A_DEFFLOAT, //B of A:B
                               0);
    //Define the handling of various inputs
    
    //Bang
    class_addbang(polybang_class, (t_method)polybang_onBangMsg);

    //List: set the ratio and reset
    class_addlist(polybang_class, (t_method)polybang_onListMsg);
    
    //Reset: start counting at 0 again
    class_addmethod(polybang_class,
                    (t_method)polybang_onResetMsg,
                    gensym("reset"),
                    0);

    //ratio_A: set A but don't reset
    class_addmethod(polybang_class,
                    (t_method)polybang_onSet_A,
                    gensym("ratio_A"),
                    A_DEFFLOAT, //A of A:B
                    0);
    
    //ratio_B: set B but don't reset
    class_addmethod(polybang_class,
                    (t_method)polybang_onSetB,
                    gensym("ratio_B"),
                    A_DEFFLOAT, //B of A:B
                    0);
    
    //Set the help file
    //This will look for "polybang-help.pd"
    class_sethelpsymbol(polybang_class, gensym("polybang"));
}