#Creating Pure Data Externals in C

##Project files

###How to use the project files

- Setup your development environment so it will compile Pure Data externals
	- [Remember to import the `m_pd.h` file from the "src" folder in the Pure Data repository]("https://github.com/pure-data/pure-data/blob/master/src/m_pd.h");
	- See the videos below on setting up your development environment or compiler in Xcode, Code::Blocks, or Linux
- Download the corresponding project file according to the table below
- Copy the contents of the file and paste into your working c file

###Table of Contents

| Lesson																	| Source code           				|
| ------------------------------------------------------------------------- | ------------------------------------- |
| [00. Introduction](https://youtu.be/_EvW4pZ7A9M) 							| N/A 									|
| [01. Configuring Xcode for development](https://youtu.be/QjLKhQ_QIcc)		| N/A									|
| [02. Writing setup and initializer code](https://youtu.be/2x5LbDvJRok)	| `02-setup-initialize.polybang.c` 		|
| [03. Initializing arguments](https://youtu.be/RsQrZyoLvp4)				| `03-initialize-arguments.polybang.c` 	|
| [04. Responding to bangs](https://youtu.be/Ysjf78lP5zw)					| `04-responding-bangs.polybang.c` 		|
| [05. Creating outlets](https://youtu.be/CsgkUpxij2U)						| `05-creating-outlets.polybang.c` 		|
| [06. Creating additional inlets](https://youtu.be/DMEqfatGzIQ)			| `06-creating-inlets.polybang.c` 		|
| [07. Responding to messages and lists](https://youtu.be/vkIARRpllFk)		| `07-messages-lists.polybang.c` 		|
| [08. Writing the logic for counting bangs](https://youtu.be/4zfntGEtJTA) 	| `08-writing-logic.polybang.c` 		|
| [09. Linking the "-help" patch](https://youtu.be/6TvT7Qtk4xM) 			| `09-linking-helper.polybang.c` 		|
| [10. Configuring Code::Blocks (PC)](https://youtu.be/7hByIk-xXXw)			| `polybang.c` 							|
| [11. Compiling with pd-lib-builder (Linux)](https://youtu.be/XCs1uzWj2IA) | `polybang.c` 							|

###Pd Patch

The final `main.pd` and `polybang-help.pd` patches are in the `test-pd` folder. As well, you'll find builds `[polybang]` like so:

| Platform  | File 					|
| --------- | --------------------- |
| OS X		| `polybang.pd_darwin`	|
| Windows	| `polybang.dll` 		|
| Linux		| `polybang.pd_linux`	|

###License

See LICENSE.txt in this folder.