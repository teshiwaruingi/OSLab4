#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
// Declare functions for the available operations.
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exitProgram(int a, int b);

// Define an array of function pointers for the operations.
int (*operations[5])(int a, int b)  = {add, subtract, multiply, divide, exitProgram};

int main (void) {
  int number; // Variable for storing the user's choice of operation.
  // Keep prompting the user for an operation until they choose to exit.
  while(number != 4) {
    // Print the operands and a list of available operations.
    printf("Operand 'a': 6 | Operand 'b': 3\n");
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    scanf("%d", &number);

    // Perform the chosen operation and print the result.
    int result = operations[number](6, 3);
    printf("X = %d\n", result);
  }
  return 0;
}


/* IMPLEMENT ME: Define your functions here */

// Function for adding two numbers.
int add (int a, int b) {
  printf ("Adding 'a' and 'b'\n");
  return a + b;
}

// Function for subtracting two numbers.
int subtract (int a, int b) {
  printf ("Subtracting 'a' and 'b'\n");
  return a - b;
}

// Function for multiplying two numbers.
int multiply (int a, int b) {
  printf ("Multiplying 'a' and 'b'\n");
  return a * b;
}

// Function for dividing two numbers.
int divide (int a, int b) {
  printf ("Dividing 'a' and 'b'\n");
  return a / b;
}

// Function for exiting the program.
int exitProgram(int a, int b) {
  exit(0);
}
