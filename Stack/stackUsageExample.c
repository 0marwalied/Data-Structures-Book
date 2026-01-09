#include "stackTemplateInC.c"

int main() {
	struct stack s;
	s.top = -1;

	push(&s, 10);
	push(&s, 20);

	int val = pop(&s);
	printf("Popped: %d\n", val);

	int testVal, isUnderflow;
	popandtest(&s, &testVal, &isUnderflow);
	if (!isUnderflow)
		printf("Popandtest got: %d\n", testVal);
	else
		printf("Stack underflow (popandtest)\n");

	return 0;
}