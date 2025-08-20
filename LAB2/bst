#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* node, int value) {
    if (node == nullptr)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) 
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\nInorder traversal before deletion:\n";
    inorder(root);
    cout << "NULL\n";

    root = deleteNode(root, 20);
    cout << "\nInorder after deleting 20:\n";
    inorder(root);
    cout << "NULL\n";

    root = deleteNode(root, 30);
    cout << "\nInorder after deleting 30:\n";
    inorder(root);
    cout << "NULL\n";

    root = deleteNode(root, 50);
    cout << "\nInorder after deleting 50:\n";
    inorder(root);
    cout << "NULL\n";

    return 0;
}
