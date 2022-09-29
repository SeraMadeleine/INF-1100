# The first assignment 
Your assignment is to write several small functions and make use of these in a C
program. 

## Task 1
Write a C function that compares two integers, and prints the largest value of
these integers to the console. For example, if the function is called with the
value 5 assigned to x and the value 10 assigned to y, the function should print
the value of y to the screen.
The C function should have the following signature:
void compare_values(int x, int y);
To solve this problem, you need to read up on how to compare values using if
statements.

## Task 2
Write a C function that prints a triangle. The number of lines in the triangle
should be a parameter to the function. For example, if the function is called
with the value 4 as an argument, the following triangle should be printed:
/ *
/ **
/ ***
/ ****
The C function should have the following signature:
void myTriangles(int numlines);
To solve this problem, you need to read up on how to express loops and how to
create nested loops in C.

## Task 3
Write a C function that determines whether a number have a given prime
factor. For example, if the function is called with the value 10 as number and 5
as primeFactor, the function should return 1 indicating that 5 is a prime factor
of 10. Similarly, the function should return 0 if the number in the example was
9.
The C Function should have the following signature:
int myPrimeFactor(int number, int primeFactor);
To solve this problem, you need to read up on use of the modulus operator in
C.

## Task 4
Write a C function  that  prints  numbers in a  given range,  along with an
indication of whether the number is odd or even and whether 5 is a prime
factor in the numbers. You must use the myPrimeFactor function to determine
whether 5 is a prime factor of the number. The function should print something
like:
1 is odd and 5 is not a prime factor
2 is even and 5 is not a prime factor
...
10 is even and 5 is a prime factor
The C function should have the following signature, where startnum indicates
what number to start printing on, and endnum indicates where to stop:
void myNumbers(int startnum, int endnum);
To solve this problem, you need to read up on use of the modulus operator in
C.

## Task 5
The binary logarithm of n(log2n) is the power to which the number 2 must be
raised to obtain the value  n. Write a C function that calculates log2 of an
unsigned integer n using the following approach: find the most significant set
bit in n and return the position of this bit. For example, if n is 17 (0b10001),
the function should return 4.
The C function should have the following signature:
int myLog2(unsigned int n);
To solve this problem, you need to read up on how to express logical and
bitwise shift operations in C.


## Task 6
Write a C function that reverses a string. In C, a string is represented as an
array of characters. The functions should manipulate the character array in
such a way that it’s content is reversed after the function has completed. If the
function was called with an array containing the characters “A string”, after the
completion of the function the array should contain “gnirts A”.
The C function should have the following signature:
void reverseString(char string[]);
To solve this problem, you need to read up on how strings are represented in
C, and how to manipulate arrays.
