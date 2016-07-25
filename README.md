#[Creating Pure Data Externals in C (2016)](https://www.youtube.com/playlist?list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)

##with Rafael Hernandez

###How to use the project files

- Setup your development environment so it will compile Pure Data externals
	- [Remember to import the `m_pd.h` file from the "src" folder in the Pure Data repository]("https://github.com/pure-data/pure-data/blob/master/src/m_pd.h");
	- See the videos below on setting up your development environment or compiler in Xcode, Code::Blocks, or Linux
- Download the corresponding project file according to the table below
- Copy the contents of the file and paste into your working c file

###Table of Contents

| Lesson																	| Source code           				|
| ------------------------------------------------------------------------- | ------------------------------------- |
| [00. Introduction](https://www.youtube.com/watch?v=041L3Q5S9qI&index=1&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz) 			| N/A 									|
| [01. Configuring Xcode for development](https://www.youtube.com/watch?v=QjLKhQ_QIcc&index=2&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)		| N/A									|
| [02. Writing setup and initializer code](https://www.youtube.com/watch?v=2x5LbDvJRok&index=3&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)	| `02-setup-initialize.polybang.c` 		|
| [03. Initializing arguments](https://www.youtube.com/watch?v=RsQrZyoLvp4&index=4&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)				| `03-initialize-arguments.polybang.c` 	|
| [04. Responding to bangs](https://www.youtube.com/watch?v=Ysjf78lP5zw&index=5&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)					| `04-responding-bangs.polybang.c` 		|
| [05. Creating outlets](https://www.youtube.com/watch?v=CsgkUpxij2U&index=6&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)						| `05-creating-outlets.polybang.c` 		|
| [06. Creating additional inlets](https://www.youtube.com/watch?v=DMEqfatGzIQ&index=7&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)			| `06-creating-inlets.polybang.c` 		|
| [07. Responding to messages and lists](https://www.youtube.com/watch?v=vkIARRpllFk&index=8&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)		| `07-messages-lists.polybang.c` 		|
| [08. Writing the logic for counting bangs](https://www.youtube.com/watch?v=4zfntGEtJTA&index=9&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz) 	| `08-writing-logic.polybang.c` 		|
| [09. Linking the "-help" patch](https://www.youtube.com/watch?v=6TvT7Qtk4xM&index=10&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz) 			| `09-linking-helper.polybang.c` 		|
| [10. Configuring Code::Blocks (PC)](https://www.youtube.com/watch?v=7hByIk-xXXw&index=11&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz)			| `polybang.c` 							|
| [11. Compiling with pd-lib-builder (Linux)](https://www.youtube.com/watch?v=XCs1uzWj2IA&index=12&list=PLn3ODBv0ka5g_zKRpmgc58-Tj-Qn-P5qz) | `polybang.c` 							|

###Pd Patch

The final `main.pd` and `polybang-help.pd` patches are in the `test-pd` folder. As well, you'll find builds `[polybang]` like so:

| Platform  | File 					|
| --------- | --------------------- |
| OS X		| `polybang.pd_darwin`	|
| Windows	| `polybang.dll` 		|
| Linux		| `polybang.pd_linux`	|

###License

See LICENSE.txt in this folder.