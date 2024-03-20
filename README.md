# _printf

This project is a Junior version of the "printf" function of the "C" programming language.
### Style
We use "Betty" coding style.
### Functions
* print_char
It is a function that prints a single character
* print_string
It is a function that prints a string of characters.
* print_dec
It is a function that prints a number of base 10
* print_mod
It is a function that print a "%" character
##### Argument List


### Instructions for use


##### Compile
In order to compile the program, we must use the following code: 

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
##### Call the function

1:
The way to call the function is to type _printf() then you can choose what you want to print by placing a string between double quotes: _printf("example").

2:
 In the case of adding a "%" followed by a specialized character (c, s, d, i, %) you will fall into the argument list.

##### Clarified example

example 1:
```
_printf("Welcome to my house");
```
It will print: Welcome to my house  

example 2:
```
char *TV = "a movie"
_printf("Let's watch %s", TV);
```
It will print: Let's watch a movie


### Flowchart of the _printf
<img src="https://i.ibb.co/VMm6FNn/printf-blue-flowchart-drawio.png">

## Authors
Pablo Espínola, Gabriel Morffe, Michael Lucas
