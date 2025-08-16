#include <stdio.h>
#include <stdlib.h>

// Define constants for stack size and boolean values
#define MAXSTACK 50
#define TRUE     1
#define FALSE    0

// Data structure to hold parameters and return addresses
struct dataArea {
	int param, x, y, retAddr; // Parameters and return address for each stack frame
};

// Stack structure to hold multiple dataArea items
struct stack {
	int top; // Top pointer of the stack
	struct dataArea item[MAXSTACK]; // Array to hold stack frames
};

// Function to push a stack frame onto the stack
void push(struct stack* s, struct dataArea* currArea) {
	s -> item[++s -> top] = *currArea;
}

// Function to pop a stack frame from the stack
void pop(struct stack* s, struct dataArea* currArea) {
	*currArea = s->item[s->top--];
}

// Simulates the computation of factorial using an explicit stack
int simulationToFactorial(int n) {
	struct dataArea currArea; // Current stack frame
	struct stack s; // Explicit stack
	short int i;
	long int result;

	// Initialize stack
	s.top = -1;
	currArea.param = currArea.x = currArea.y = currArea.retAddr = 0;

	// Push the initial stack frame
	push(&s, &currArea);

	// Set the initial parameters
	currArea.param = n;
	currArea.retAddr = 1;

	// Forward phase of recursion simulation
forward:
	if (currArea.param == 0) {
		// Base case: factorial of 0 is 1
		result = 1;
		i = currArea.retAddr;
		pop(&s, &currArea); // Pop the stack frame
		switch (i) {
		case 1: goto end;
		case 2: goto backward;
		}
	}
	// Recursive case: prepare next stack frame
	currArea.x = currArea.param - 1;
	push(&s, &currArea); // Push the current stack frame
	currArea.param = currArea.x;
	currArea.retAddr = 2;
	goto forward;

	// Backward phase of recursion simulation
backward:
	currArea.y = result;
	result = currArea.y * currArea.param; // Combine results
	i = currArea.retAddr;
	pop(&s, &currArea); // Pop the stack frame
	switch (i) {
	case 1: goto end;
	case 2: goto backward;
	}

end:
	// Return the computed factorial
	return (result);
}

int main() {
	// Compute and print the factorial of 5
	printf("%d\n", simulationToFactorial(5));
	return 0;
}
