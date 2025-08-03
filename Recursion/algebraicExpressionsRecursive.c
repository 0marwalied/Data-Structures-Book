#include <stdio.h>
#include <ctype.h>
#define TRUE          1
#define FALSE         0
#define MAXSTRINGSIZE 100

// Function prototypes
void readstr(char *, int*);                // Reads the input string from the user
int expr(char *, int , int *);             // Checks if the input string is a valid expression
int term(char *, int , int *);             // Checks if the input string is a valid term
int getsymb(char *, int , int *);          // Retrieves the next character from the input string
int factor(char *, int , int *);           // Checks if the input string is a valid factor

int main() {
	// Main function to execute the program
	int pos = 0, length;                   // Position tracker and length of the input string
	char str[MAXSTRINGSIZE];               // Buffer to hold the input string

	// Read the input string
	readstr(str, &length);

	// Validate the expression and print the result
	if (expr(str, length, &pos) == TRUE && pos >= length) {
		printf("%s\n", "valid");           // Print "valid" if the expression is correct
	} else {
		printf("%s\n", "Not valid");       // Print "Not valid" if the expression is incorrect
	}
}

void readstr(char str[], int *length) {
	// Reads the input string from the user and calculates its length
	printf("Enter the expression: ");
	fgets(str, MAXSTRINGSIZE, stdin);      // Safely reads the input string

	// Remove the newline character added by fgets and compute the length
	int position = 0;
	while (str[position] != '\0' && str[position] != '\n') {
		position++;
	}
	str[position] = '\0';                  // Replace newline character with null terminator
	*length = position;                    // Store the length of the input string
}

int getsymb(char str[], const int length, int *ppos) {
	// Retrieves the next character from the input string, skipping spaces
	int c;

	// Skip spaces in the input string
	while (*ppos < length && str[*ppos] == ' ') (*ppos)++;

	// Get the next character or return a space if out of bounds
	if (*ppos < length)
		c = str[*ppos];
	else
		c = ' ';
	(*ppos)++;                             // Increment the position pointer
	return c;                              // Return the retrieved character
}

int factor(char str[], const int length, int *ppos) {
	// Checks if the input string is a valid factor
	int c;

	// A factor is either a single letter or an expression enclosed in parentheses
	if ((c = getsymb(str, length, ppos)) != '(')
		return isalpha(c);                 // Valid if it's a letter
	return expr(str, length, ppos) && getsymb(str, length, ppos) == ')';
}

int term(char str[], const int length, int *ppos) {
	// Checks if the input string is a valid term
	// A term is either a factor or a factor followed by '*'

	if (factor(str, length, ppos) == FALSE) {
		return FALSE;                      // Not valid if the factor is invalid
	}

	// Check for the multiplication operator '*'
	if (getsymb(str, length, ppos) != '*') {
		(*ppos)--;                         // Step back if not '*'
		return TRUE;                       // Valid if there's no '*'
	}
	return factor(str, length, ppos);      // Validate the second factor
}

int expr(char str[], const int length, int *ppos) {
	// Checks if the input string is a valid expression
	// An expression is either a term or a term followed by '+'

	if (term(str, length, ppos) == FALSE)
		return FALSE;                      // Not valid if the term is invalid

	// Check for the addition operator '+'
	if (getsymb(str, length, ppos) != '+') {
		(*ppos)--;                         // Step back if not '+'
		return TRUE;                       // Valid if there's no '+'
	}
	return term(str, length, ppos);        // Validate the second term
}