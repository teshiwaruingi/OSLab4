#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exitProgram(int a, int b);

int (*operations[5])(int a, int b)  = {add, subtract, multiply, divide, exitProgram};

int main (void)
{
  int number;
	/* IMPLEMENT ME: Insert your algorithm here */
  while(number != 4) {
  printf("Operand 'a':6|Operand 'b': 3\n");
  printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit):");
  scanf("%d", &number);
  int result = operations[number](6, 3);
  printf("X = %d\n", result);
  }
  
	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int subtract (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b; }
int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }
int divide (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b; }
int exitProgram(int a, int b) { exit(0); }