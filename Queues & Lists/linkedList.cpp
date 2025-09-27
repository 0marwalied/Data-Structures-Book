#include <iostream>

struct Node {
	int info;
	Node *next;
};

Node* getnode() {
	return new Node();
};

void freenode(Node *p) {
	delete(p);
}

void insafter(Node *p, int x) {
	if (p == NULL) {
		std::cout << "Invalid insertion\n";
		exit(1);
	}
	Node *q = getnode();
	q->info = x;
	q->next = p->next;
	p->next = q;
}

void delafter(Node *p, int *px) {
	if ((p == NULL) || (p->next == NULL)) {
		std::cout << "Invalid deletion\n";
		exit(1);
	}
	Node *q = p->next;
	*px = q->info;
	p->next = q->next;
	freenode(q);
}

int main() {

}