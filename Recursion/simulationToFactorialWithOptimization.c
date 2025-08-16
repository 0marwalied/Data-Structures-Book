#include <stdio.h>
#include <stdlib.h>

// Define constants for stack size and boolean values
#define MAXSTACK 50
#define TRUE     1
#define FALSE    0

// Stack structure for storing parameters
struct stack {
	int top; // Top pointer of the stack
	int param[MAXSTACK]; // Array to hold parameters
};

// Function to pop from the stack and test if it's empty
void popAndTest(struct stack* s, int* x, short int* und) {
	*und = FALSE;
	if (s->top == -1) *und = TRUE; // Stack is empty
	else *x = s->param[s->top--]; // Pop the top element
}

// Function to push a parameter onto the stack
void Push(struct stack* s, int x) {
	s -> param[++s -> top] = x;
}

// Optimized simulation of factorial computation
int simulationToFactorialWithOptimization(int n) {
	long int y; // Result variable
	int x; // Current parameter
	short int und; // Flag for stack underflow
	struct stack s; // Explicit stack
	s.top = -1; // Initialize stack
	x = n; // Set initial parameter

	// Forward phase of recursion simulation
forward:
	if (x == 0) {
		// Base case: factorial of 0 is 1
		y = 1;
	} else {
		// Recursive case: push parameter and continue
		Push(&s, x--);
		goto forward;
	}

	// End and backward phase of recursion simulation
end: popAndTest(&s, &x, &und);
	if (und == TRUE)
		// If stack is empty, return the result
		return (y);
backward: y *= x; // Combine results
	goto end;
}

int main() {
	// Compute and print the factorial of 5
	printf("%d\n", simulationToFactorialWithOptimization(5));
	return 0;
}
