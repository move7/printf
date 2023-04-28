

Here we present ``_print``, is a customized implementation of the printf function in C. 

This Alx project is a great opportunity to to set up our c language knowledge. 

 # _printf
> Print formatted data to stdout

*Prototye :*

**int printf ( const char * format, ... );**

## Parameters 
**`format`** - String that contains the text to be written to stdout. It can optionally contain embedded format specifiers that are replaced by the values specified in subsequent additional arguments and formatted as requested.

*Format tags prototype* :
>``` %[flags][width][.precision][length]specifier```

- **Specifier character** at the end is the most significant component,component, defining the type and interpretation of the argument.

| Format | Description |
| -- | --- |
|%c	|print a single character|
|%d	|print a decimal (base 10) number|
|%e	|print an exponential floating-point number|
|%f	|print a floating-point number|
|%g	|print a general-format floating-point number|
|%i	|print an integer in base 10|
|%o	|print a number in octal (base 8)|
|%s	|print a string of characters|
|%u	|print an unsigned decimal (base 10) number|
|%x	|print a number in hexidecimal (base 16)|
|%%	|print a percent sign (\% also works)|

- **Flags** is optional 

| Flag | Description |
| -- | --- |
|- |Left justify.|
|0|Field is padded with 0's instead of blanks.|
|+|Sign of number always O/P.|
|blank|Positive values begin with a blank.|
|#| Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero.<br> Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow.<br> By default, if no digits follow, no decimal point is written. <br>Used with g or G the result is the same as with e or E but trailing zeros are not removed |

- **width** is optional

| width | Description |
| -- | --- |
|(number) |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|\*|The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

- **.precision** is optional

|.precision|	description|
| -- | --- |
|.number|For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.<br>For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).<br>For g and G specifiers: This is the maximum number of significant digits to be printed.<br>For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.<br>If the period is specified without an explicit value for precision, 0 is assumed.|
|.\*|	The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

- **width** is optional

|width|	description|
| -- | --- |
|h|The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X).|
|l|The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s.|
|L|The argument is interpreted as a long double (only applies to floating point specifiers: e, E, f, g and G).|

### Example :
**Code :**
```
/* Example for printf() */
#include <stdio.h>

int main(){
   printf ("Integers: %i %u \n", -3456, 3456);
   printf ("Characters: %c %c \n", 'z', 80);
   printf ("Decimals: %d %ld\n", 1997, 32000L);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
   printf ("Preceding with empty spaces: %10d \n", 1997);
   printf ("Preceding with zeros: %010d \n", 1997);
   printf ("Width: %*d \n", 15, 140);
   printf ("%s \n", "Educative");
   return 0;
}
```
**Output :**
```
Integers: -3456 3456 
Characters: z P 
Decimals: 1997 32000
Some different radices: 100 64 144 0x64 0144 
floats: 3.14 +3e+00 3.141590E+00 
Preceding with empty spaces:       1997 
Preceding with zeros: 0000001997 
Width:             140 
Educative 
```
## Project Requirements
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic
* Code must follow the [Betty](https://github.com/holbertonschool/Betty/wiki) style
* Global variables are not allowed
* Authorized functions and macros:
  * ```write``` (man 2 write)
  * ```malloc``` (man 3 malloc)
  * ```free``` (man 3 free)
  * ```va_start``` (man 3 va_start)
  * ```va_end``` (man 3 va_end)
  * ```va_copy``` (man 3 va_copy)
  * ```va_arg``` (man 3 va_arg)

## Mandatory Tasks
- [x] Write function that produces output with conversion specifiers ```c```, ```s```, and ```%```.
- [x] Handle conversion specifiers ```d```, ```i```.
- [x] Create a man page for your function.
## Advanced Tasks
- [x] Handle conversion specifier ```b```.
- [x] Handle conversion specifiers ```u```, ```o```, ```x```, ```X```.
- [x] Use a local buffer of 1024 chars in order to call write as little as possible.
- [x] Handle conversion specifier ```S```.
- [x] Handle conversion specifier ```p```.
- [x] Handle flag characters ```+```, space, and ```#``` for non-custom conversion specifiers.
- [ ] Handle length modifiers ```l``` and ```h``` for non-custom conversion specifiers.
- [ ] Handle the field width for non-custom conversion specifiers.
- [ ] Handle the precision for non-custom conversion specifiers.
- [ ] Handle the ```0``` flag character for non-custom conversion specifiers.
- [x] Handle the custom conversion specifier ```r``` that prints the reversed string.
- [x] Handle the custom conversion specifier ```R``` that prints the rot13'ed string.
- [ ] All above options should work well together.
## File Descriptions
**_printf.c**
* contains the  fucntion ```_printf```, which uses the prototype ```int _printf(const char *format, ...);```. The format string is composed of zero or more directives. See ```man 3 printf``` for more detail. **_printf** will return the number of characters printed (excluding the null byte used to end output to strings) and will write output to **stdout**, the standard output stream.

**_putchar.c**
* contains the function ```_putchar```, which writes a character to stdout.

**holberton.h**
*contains all function prototypes used for ```_printf```.

**man_3_printf**
* manual page for the custom ```_printf``` function.

**functions.c** **functions1.c** **functions2.c**
* contains all function of each specifier used for ```_printf```.
* all function have its own description inside the file.

**handle_print.c**
* contains arguments types used for ```_printf```.

**get_flags.c**
* contains all function for each flag use for ```_printf```.

**utils.c**
* contains some necessary functionalities for ```_printf```.

**ger_width.c**
* contains functions to get width for spcifics spcifiers.

**writee_handlers.c**
* contains write functions.

## Directory Descriptions
**tests**
* contains the test cases for ```_printf```.

## Authors
[Sara HAIMER](https://github.com/move7) | [Fatima EL ADDOUNI](https://github.com/move7)




