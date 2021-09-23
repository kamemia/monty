# 0x19. C - Stacks, Queues - LIFO, FIFO
  Done by Vincent Kamemia for ALX SE
## Monty Interpreter
  This interpreter is built in the C programming language. It reads Monty bytecode files of any extensions, preferably `.m`, and it interprets the opcodes contained. it can be run as either a stack (LIFO) or queue (FIFO). 
## Requirements
* [Ubuntu 14.04 LTS](http://releases.ubuntu.com/20.04/) Operating System
* [GCC 11.2](https://gcc.gnu.org/gcc-11/) Compiler
* Installation of Git (`sudo apt-get install git`)
* Cloning of repo (`git clone https://github.com/Annette-Munyiri/monty.git`)
## Compiling
  The interpreter is compiled using the following line of code assuming the GCC compiler is installed and ready to run:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
## Running Monty
  Monty is run using this line of code in your command line:
```
./monty file.m
```
## Coding Style 
  The Betty style guide was used to write the code to generate the interpreter.
## Author
[Vincent Kamemia](https://github.com/kamemia)