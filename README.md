# braf
### A Brainfuck Interpreter
###### Copyright (C) 2015 Sean Ballais, Bea Santiago, Ivan Puayap, Kenneth Cu

braf is a Brainfuck interpreter written in C. It accepts text files as source files. It also features an interactive mode in any case someone wants to try out Brainfuck.

### Brainfuck
Brainfuck is a Turing-complete minimalistic programming language that only has 8 commands. In this language, values are stored in a character array called a tape containing 30,000 cells. A data pointer points to the current active cell where any values will be stored. The commands available in Brainfuck are listed below.
```
+    Increment the value of the current cell by one.    
-    Decrement the value of the current cell by one.    
.    Print the current cell.    
,    Input a value and store it in the current cell.    
<    Move the data pointer to the cell to the left of the current cell.    
>    Move the data pointer to the cell to the right of the current cell.    
[    Start of a loop. Skip the loop when the value of the current cell is 0.    
]    End of a loop. Skip the loop when the value of the current cell is 0.    
```

It's that simple!

### Using braf
braf is ran from the Terminal. Here's the list of commands available in braf.

```
Usage: braf [options] <input files>    
Options:    
-h --help               Display this help text    
-v --version            Display braf version and additional information.     
-i --interactive        Explicitly enable interactive mode.    
                        Interactive mode can be initialized by not including any flags.    
-d, --debug, --verbose  Enable debug mode. braf will display the values of the modified cells, and any performed operations.     
```

braf can accept multiple input files.

### Compiling braf
Compiling braf is primarily performed by a Bash script that utilizes the CMake build system. Make sure CMake (version >= 2.8) is installed in your system. The build script will install the compiled files in a `bin` folder, while the braf header file will be installed in a `include` folder. To install braf in a different directory, edit `CMAKE_INSTALL_PREFIX` in `build.sh` to make sure braf will be installed in your specified directory.

```
$ cd /path/to/braf/code        
$ chmod +x build.sh    
$ ./build.sh    
```    

braf can also be compiled manually. braf has been designed to not depend on any third party libraries to eliminate dependencies and make is simpler. To compile manually, type the following in the terminal. Make sure a C compiler that supports C99 or C11 is installed in your system.

```
$ clang -Werror -Wall -std=c11 -g src/util.c src/error_check.c src/process_files.c src/braf.c src/interactive_mode.c src/main.c -o bin/braf    
```

### braf Library
braf provides a static library that can be embedded inside applications.

#### Using the braf library
To use braf inside your applications, include the braf header file at the top of your application. Then link the braf library to your application during compilation.

The braf library only contains one function, `braf_interpretCode()`.


    unsigned int braf_interpretCode(const char &ast;code, char &ast;dataPtr, bool verbose);

`*code`         The Brainfuck code that you want to interpret.    
`*dataPtr`      Pointer to an application's tape. The application must provide its own tape.    
`verbose`       When set to true, the library will print out any operations, such as incrementing or decrementing values, done during interpretation.    
*Return value*: returns 1 if an error occurred, returns 0 otherwise.     

#### Compiling the braf library
If you compiled braf using `./build.sh`, the braf library will be compiled also.    
If you prefer compiling the library manually, type the following in the terminal.


    $ clang -Werror -Wall -std=c11 -g src/util.c src/error_check.c src/process_files.c src/braf.c -o libbraf-dev

### Copyright
Copyright &copy; 2015. All Rights Reserved. Sean Ballais, Bea Santiago, Kenneth Cu, & Ivan Puayap.

### License
braf is licensed under the MIT License. View the license [here](LICENSE.md).
