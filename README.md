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

**It's that simple!**

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
