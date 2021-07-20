#include <iostream>
using namespace std;

class MyQueue {
    private:
        struct Node {
            int data;
            Node *next;
            Node(int d) : data(d) {}
        };

        Node *head;
        Node *tail;

    public:
        MyQueue() {
            head = nullptr;
            tail = nullptr;
        }

        bool isEmpty() {
            return head == nullptr;
        }

        int top() {
            if(head == nullptr)
                throw std::string("Underflow!!!");
            return head->data;
        }

        void push(int data) {
            Node* newNode = new Node(data);
            if(tail != nullptr)
                tail->next = newNode;
            tail = newNode;
            if(head == nullptr)
                head = newNode;
        }

        void pop() {
            if(head != nullptr) {
                Node *aux = head;
                head = head->next;
                delete(aux);
            }
            if(head == nullptr)
                tail = nullptr;
        }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << q.top() << endl;
}