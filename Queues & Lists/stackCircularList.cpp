#include "iostream"

using namespace std;

class Node {
   private:
    int val;
    Node* next;

   public:
    Node* getNode() { return new Node(); }
    bool isEmpty(Node* stk) { return stk == NULL; }
    void push(Node* stk, int val) {
        Node* p = getNode();
        p->val = val;
        if (isEmpty(stk))
            stk = p;
        else
            p->next = stk->next;
        stk->next = p;
    }
    int pop(Node* stk) {
        if (isEmpty(stk)) {
            cout << "Stack is empty\n";
            exit(1);
        }
        Node* p = stk->next;
        int ret = p->val;
        if (stk == p) {
            stk = NULL;
        } else {
            stk->next = p->next;
        }
        delete p;
        return ret;
    }
};

int main() {
    Node* stk = new Node();
    stk->push(stk, 10);
    stk->push(stk, 20);
    stk->push(stk, 30);
    cout << stk->pop(stk) << "\n";
    cout << stk->pop(stk) << "\n";
    cout << stk->pop(stk) << "\n";
    return 0;
}