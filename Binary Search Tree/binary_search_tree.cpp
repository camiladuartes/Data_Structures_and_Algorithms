#include <iostream>

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;

    BstNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BstNode* insert(BstNode *root, int data) {
    // Empty tree
    if(root == NULL) {
        root = new BstNode(data);
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data) {
    if(root == NULL) return false;
    if(root->data == data) return true;
    if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int main() {
    BstNode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    int number;
    std::cout << "Enter a number to be searched:\n";
    std::cin >> number;
    if(Search(root, number)) std::cout << "Found!\n";
    else std::cout << "Not found\n";
}



// class Node {
//     int data;
//     Node *left, *right;
    
//     public:
//     Node(int val) : data(val), left(nullptr), right(nullptr) { }
    
//     Node* insert(Node *root, int val) {
//         if(!root) {
//             return new Node(val);
//         }
//         if(val <= root->data) {
//             return insert(root->left, val);
//         }
//         else {
//             return insert(root->right, val);
//         }
//         return root;
//     }
// };