#include <iostream>
using namespace std;

class MyStack {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int d) : data(d) {}
        };

        Node* top;
    
    public:
        MyStack() {
            top = nullptr;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        int top_() {
            if(top == nullptr)
                throw std::string("Underflow!!!");
            return top->data;
        }

        void push(int data) {
            Node* newNode = new Node(data);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if(top != nullptr) {
                Node *aux = top;
                top = top->next;
                delete(aux);
            }
        }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.top_() << endl;
}