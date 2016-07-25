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
      
    //Return the instance
    return (void *)x;
}

//The _setup method initializes the class in memory
//This method is the place where class behaviors are added
//It is required to be named [filename]_setup()
void polybang_setup(void){
    //Initialize the class
    polybang_class = class_new(gensym("polybang"),
                               (t_newmethod)polybang_new,
                               0,
                               sizeof(t_polybang),
                               CLASS_DEFAULT,
                               A_DEFFLOAT, //A of A:B
                               A_DEFFLOAT, //B of A:B
                               0);
}