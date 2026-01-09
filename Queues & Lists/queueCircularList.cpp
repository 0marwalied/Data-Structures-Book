#include "iostream"

using namespace std;

class Node {
   private:
    int val;
    Node* next;

   public:
    Node* getNode() { return new Node(); }
    bool isEmpty(Node* queue) { return queue == NULL; }
    void enque(Node*& queue, int val) {
        Node* p = getNode();
        p->val = val;
        if (isEmpty(queue)) {
            queue = p;
            p->next = p;
        } else {
            p->next = queue->next;
            queue->next = p;
            queue = p;
        }
    }
    int pop(Node*& queue) {
        if (isEmpty(queue)) return -1;
        Node* p = queue->next;
        int ret = p->val;
        if (queue == p)
            queue = NULL;
        else
            queue->next = p->next;
        delete p;
        return ret;
    }
};

int main() {
    Node* queue = NULL;
    queue->enque(queue, 10);
    queue->enque(queue, 20);
    queue->enque(queue, 30);
    cout << queue->pop(queue) << endl;  // 10
    cout << queue->pop(queue) << endl;  // 20
    cout << queue->pop(queue) << endl;  // 30
    cout << queue->pop(queue) << endl;  // -1
    return 0;
}