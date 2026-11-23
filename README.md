*This activity has been created as part of the 42 curriculum by jhoflehn.*

## Description ##

This program was written to better understand, how different functions in the common libraries work. It contains six functions, each handling different input types from the user. Two of those functions handle multible cases, coming to a total of 9 possible input types.

## Instructions ##

This are the samples, a reviewer might use to test the program. They compare the output of the original printf to the homemade one.

```
 #include "ft_printf.h"

int main (void)
{
	int a;
	void *ptr = &a; 
	ft_printf("Printed: %i\n", 
	ft_printf("this is a test using ft_printf.\nChar %c\nString %s\nPointer %p\n", 'w',
	"does it work?", ptr));
	ft_printf("Decimal %d\nInteger %i\n", -5, -12);
	ft_printf("Unsigned: Decimal %u\nUpperHex %X\nLowerHex %x\nPercent sign: %%\n", 550, 42, 42);
	printf("Printed: %i\n", 
	printf("this is a test using the original.\nChar %c\nString %s\nPointer %p\n", 'w',
	"does it work?", ptr));
	printf("Decimal %d\nInteger %i\n", -5, -12);
	printf("Unsigned: Decimal %u\nUpperHex %X\nLowerHex %x\nPercent sign: %%\n", 550, 42, 42);
} 
```

## Resources ##

In writing this program, I had help from peers and once I was done, I used printf tester from Github to see, if common edge cases were handled correctly. AI was used to learn about "stdarg" and pointer handling.

## Additions ##

The building of the algorithm was rather straight forward. It iterates through the passed string, looking for identifiers. Using those, the variable arguments get delegated to the proper functions for handling.
- Single chars and strings get written to the console piece by piece.
- The pointers get translated to hexadecimal and put out with a leading "0x".
- Signed numbers get type-casted to long and turned positive for handling. They are recursively broken down and put out.
- Unsigned numbers - hexadecimal, decimal and integers - are also safed as long and recursivley put out using the proper base.

All of the used "put" - functions count the number of printed characters to be returned by the main ft_printf.