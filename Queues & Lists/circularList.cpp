#include "iostream"

using namespace std;

class Node {
   private:
    int val;
    Node* next;

   public:
    Node* getNode() { return new Node(); }
    bool isEmpty(Node* list) { return list == NULL; }
    void push(Node* list, int val) {
        Node* p = getNode();
        p->val = val;
        if (isEmpty(list))
            list = p;
        else
            p->next = list->next;
        list->next = p;
    }
    int pop(Node* list, int val) {
        if (isEmpty(list)) {
            cout << "List is empty\n";
            exit(1);
        }
        Node* p = list;
        while (p->next->val != val) {
            p = p->next;
            if (p == list) {
                cout << "Value not found\n";
                exit(1);
            }
        }
        Node* q = p->next;
        int ret = q->val;
        p->next = q->next;
        delete q;
        return ret;
    }
    void printList(Node* list) {
        if (isEmpty(list)) {
            cout << "List is empty\n";
            return;
        }
        Node* p = list->next;
        do {
            cout << p->val << " ";
            p = p->next;
        } while (p != list->next);
        cout << "\n";
    }
};

int main() {
    Node* list = new Node();
    list->push(list, 10);
    list->push(list, 20);
    list->push(list, 40);
    list->pop(list, 20);
    list->printList(list);
}