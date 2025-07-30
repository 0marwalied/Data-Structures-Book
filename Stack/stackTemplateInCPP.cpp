#include <iostream>

#define stacksize 100

using namespace std;

template <class T> class stack {
private:
	int top;
	T *nodes;
public:
	stack() {
		top = -1, nodes = new T[stacksize];
	}

	int size() {
		return top + 1;
	}

	bool empty() {
		return top == -1;
	}

	void push(T val) {
		if (top == stacksize)
			throw runtime_error("Stack Overflow");
		nodes[top++] = val;
	}

	T pop() {
		if (top == -1)
			throw runtime_error("Stack Underflow");
		T val = nodes[--top];
		return val;
	}

	~stack() {
		delete nodes;
	};
};