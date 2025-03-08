#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
Node* findNode(Node* root, int value) {
    while (root != NULL && root->data != value) {
        if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

Node *inorderSuccessor(Node *root, Node *p) {
    Node *successor = NULL;
    while (root != NULL) {
        if (p->data < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 1);
    insert(root, 8);
    insert(root, 10);

    Node *p = findNode(root, 8); // Node with value 8
    if (p == NULL) {
        cout << "Node with value 8 not found in the tree." << endl;
        return 0;
    }

    Node *result = inorderSuccessor(root, p);
    if (result) {
        cout << "Inorder Successor of " << p->data << " is " << result->data << endl;
    } else {
        cout << "Inorder Successor of " << p->data << " does not exist." << endl;
    }

    return 0;
}
