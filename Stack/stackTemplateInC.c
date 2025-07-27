#include <stdlib.h>
#include <stdio.h>

#define STACKSIZE 100
#define INT       1
#define FLOAT     2
#define STRING    3

// Defined but currently unused
struct stackelement {
	int etype; // INT, FLOAT, or STRING
	union {
		int ival;
		float fval;
		char *pval; // Pointer to a string
	} element;
};

struct stack {
	int top;
	int items[STACKSIZE];
};

int empty(struct stack *s) {
	return s->top == -1;
}

int pop(struct stack *s) {
	if (empty(s)) {
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	return s->items[s->top--];
}

void popandtest(struct stack *s, int *x, int *isund) {
	if (empty(s)) {
		*isund = 1;
	} else {
		*isund = 0;
		*x = s->items[s->top--];
	}
}

void push(struct stack *s, int val) {
	if (s->top == STACKSIZE - 1) {
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	s->items[++s->top] = val;
}

void pushandtest(struct stack *s, int x, int *overflow) {
	if (s->top == STACKSIZE - 1) {
		*overflow = 1;
	} else {
		*overflow = 0;
		s->items[++s->top] = x;
	}
}

int top(struct stack *s) {
	if (empty(s)) {
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	return s->items[s->top];
}