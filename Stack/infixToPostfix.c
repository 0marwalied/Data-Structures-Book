#include "stackTemplateInC.c"

int prcd(const char c1, const char c2) {
	if (c1 == '^' && c2 == '*')return TRUE;
	if (c1 == '^' && c2 == '/')return TRUE;
	if (c1 == '^' && c2 == '+')return TRUE;
	if (c1 == '^' && c2 == '-')return TRUE;
	if (c1 == '*' && c2 == '+')return TRUE;
	if (c1 == '*' && c2 == '-')return TRUE;
	if (c1 == '/' && c2 == '+')return TRUE;
	if (c1 == '/' && c2 == '-')return TRUE;
	return FALSE;
}

int isoperand(const double symb) {
	return ('0' <= symb && symb <= '9');
}

void postfix(char infix[], char postr[]) {
	int position, und, outpos = 0;
	double symb;
	int topsymb = '+';
	struct stack ospstk; ospstk.top = -1;

	for (position = 0; (symb = infix[position]) != '\0'; position++) {
		if (isoperand(symb))
			postr[outpos++] = ' ', postr[outpos++] = symb;
		else if (symb != ' ') {
			popandtest(&ospstk, &topsymb, &und);
			while (!und && prcd(topsymb, symb)) {
				postr[outpos++] = ' ', postr[outpos++] = topsymb;
				popandtest(&ospstk, &topsymb, &und);
			}
			if (!und)
				push(&ospstk, topsymb);
			if (und || symb != ')')
				push(&ospstk, symb);
			else
				topsymb = pop(&ospstk);
		}
	}

	while (!empty(&ospstk))
		postr[outpos++] = pop(&ospstk);

	postr[outpos] = '\0';
	return;
}