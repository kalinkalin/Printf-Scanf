## Printf and scanf functions


At first i want to emphasize that i work on simplified model of 32 bit architecture, where i can expect that arguments passed to a functions are pushed on stack one by one. Programme must be compiled in 32 bit mode, in gcc there is accurate flag `-m32`.

   Example of compilation in gcc: `gcc myprintf.c -m32`

On some newer architectures we cannot expect to find all arguments on the stack as they are passed in other way, certainly not on x86-64 architecture, in which some values are passed in registers.

<hr>

### Variadic funtions and usage

Printf and scanf are functions which can take variable numbers of arguments, such functions in c are called variadic functions. Syntax of this functions is `function_head(first_argument,...)`, where `...`(so called elipsies) means unknown number of arguments. More about variadic functions [here](https://www.thegeekstuff.com/2017/05/c-variadic-functions/). In my implementation first argument is formated string passed to printf, for example `"write: %d %s"`, after that there are passed arguments to print. It is easy to get memory adress of this string. Acessing another values is just incrementing current memory adress by size of given type, as all values are on stack on by one. There is simple char-by-char parser, which prints normal chars using syscall write and if the given char is % it is getting value at given adress printing it and incrementing the pointer by its size. Scanf is analogous.

**Avaliable types:**
   * `%d` - printing decimal integer
   * `%s` - printing string
   * `%x` - printing hexadecimal integer
   * `%b` - printing binary integer
