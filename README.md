## Printf and scanf functions


At first i want to emphasize that i work on simplified model of 32 bit architecture, where i can expect that arguments passed to a functions are pushed on stack one by one. Programme must be compiled in 32 bit mode, in gcc there is accurate flag `-m32`.

   Example of compilation in gcc: `gcc myprintf.c -m32`

On some newer architectures we cannot expect to find all arguments on the stack as they are passed in other way, certainly not on x86-64 architecture, in which some values are passed in registers.

<hr>

### Variadic funtions and usage
