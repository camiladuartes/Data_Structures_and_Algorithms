#include <iostream>

/// Douby Linked-List
class myList {
    public:

    struct Node {
        int data;
        Node *next;
        Node *prev;

        Node(int d = NULL, Node *p = nullptr, Node *n = nullptr) : data(d), prev(p), next(n) {}
    };

    int m_size;
    Node *m_head;
    Node *m_tail;

    myList() {
        m_head = new Node();
        m_tail = new Node();
        m_tail->prev = m_head;
        m_head->next = m_tail;
        m_size = 0;
    }
    
    /*!
     * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    int get(int index) {
        Node *aux = m_head;
        if(index >= m_size or index < 0) return -1;
        for(int i = 0; i < m_size; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    /*! Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked list.
     */
    void addAtHead(int val) {
        Node *node = new Node(val, m_head, m_head->next);
        m_head->next = node;
        node->next->prev = node;
        m_size += 1;
    }

    /*! Append a node of value val to the last element of the linked list.
     */
    void addAtTail(int val) {
        Node *node = new Node(val);
        node->next = m_tail;
        m_tail->prev->next = node;
        node->prev = m_tail->prev;
        m_tail->prev = node;
        m_size += 1;
    }

    /*! Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
     * the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
     */
    void addAtIndex(int index, int val) {
        if(index >= m_size or index < 0) return;
        Node *node = new Node(val);
        Node *aux = m_head;
        m_size += 1;
        if(index == 0)
            addAtHead(val);
        else if(index == m_size)
            addAtTail(val);
        else {
            for(int i = 0; i < index-1; i++) aux = aux->next;
            node->next = aux;
            node->prev = aux->prev;
            aux->prev->next = node;
            aux->prev = node;
        }

    }

    /*! Move forward twice the head pointer, if it ends with null is even, otherwise is odd
     */
    bool isLengthEvenOrOdd(Node *head) {
        while(head != nullptr and head->next != nullptr) {
            head->next->next;
        }

        if(head == nullptr)
            std::cout << "Even" << std::endl;
        else
            std::cout << "Odd" << std::endl;
    }

    /*! Reverse List: 
     */
    Node* reverse(Node* head) {
        if(head == nullptr or head->next == nullptr) return head;
        
        Node *currentHead = head;
        Node *aux = head;
        Node *toSwap = head->next;
        
        while(toSwap != nullptr) {
            Node *newNode = new Node(toSwap->data);
            newNode->next = currentHead;
            currentHead = newNode;
            toSwap = toSwap->next;
            aux->next = toSwap;
        }
        
        head = currentHead;
        return head;
    }

};

int main() {
    myList list;

    // myList::Node node_1(1);

    list.addAtIndex(0, 1);
    list.addAtIndex(1, 2);
    list.addAtIndex(2, 3);

    std::cout << list.get(0) << std::endl;
    std::cout << list.get(1) << std::endl;
    std::cout << list.get(2) << std::endl;
}