#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOpening(const char& c) {
	return c == '(' || c == '{' || c == '[';
}

bool isClosing(const char& c) {
	return c == ')' || c == '}' || c == ']';
}

bool matching(const char& open, const char& close) {
	return (open == '(' && close == ')') ||
	       (open == '{' && close == '}') ||
	       (open == '[' && close == ']');
}

bool validateNestedScopes(const string& expression) {
	stack<char> stk;

	for (const char& ch : expression) {
		if (isOpening(ch)) {
			stk.push(ch);
		} else if (isClosing(ch)) {
			if (!stk.empty() && matching(stk.top(), ch)) {
				stk.pop();
			} else {
				return false;
			}
		}
	}

	return stk.empty();
}