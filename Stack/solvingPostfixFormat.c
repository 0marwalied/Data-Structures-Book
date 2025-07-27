#include "stackTemplateInC.c"
#include "math.h"

#define MAXCOLS 80

int isDigit(const int symb) {
	return ('0' <= symb && symb <= '9');
}

double oper(char symb, double opnd1, double opnd2) {
	switch (symb) {
	case '+': return (opnd1 + opnd2);
	case '-': return (opnd1 - opnd2);
	case '*': return (opnd1 * opnd2);
	case '/': return (opnd1 / opnd2);
	case '^': return (pow(opnd1, opnd2));
	default: printf("%s", "illegal operation");
		exit(EXIT_FAILURE);
	}
}

double eval(char expr[]) {
	int c, postition;
	double opnd1, opnd2, value;
	struct stack s; s.top = -1;
	for (postition = 0; (c = expr[postition]) != '\0'; postition++) {
		if (isDigit(c)) {
			push(&s, (double)(c - '0'));
		} else if (c != ' ') {
			opnd2 = pop(&s);
			opnd1 = pop(&s);
			value = oper(c, opnd1, opnd2);
			push(&s, value);
		}
	}
	return (pop(&s));
}

void handleString(char expr[]) {
	int postition = 0;
	while ((expr[postition++] = getchar()) != '\n');
	expr[--postition] = '\0';
}

// A + B called infix
// + A B called prefix
// A B + called postfix

// Converting the infix expression to postfix experession
// A + ( B * C)
// A + ( BC * )
// A ( BC * ) +
// A BC * +

// Steps for solving this -> A $ B * C - D + E / F / ( G + H )
// note ^ equal to power
// A ^ B * C - D + E / F / ( GH + )
// AB ^ * C - D + E / F / ( GH + )
// ( AB ^ C * ) - D + E / F / ( GH + )
// ( AB ^ C * ) - D + ( EF / ) / (GH+)
// ( AB ^ C * ) - D + ( EF /) ( GH + ) /
// ( AB ^ C * D - )  + ( ( EF / ) ( GH + ) / )
// AB ^ C * D - EF / GH + / +