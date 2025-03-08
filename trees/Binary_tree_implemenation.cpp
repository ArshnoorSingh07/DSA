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
Node* buildTree(Node *root) {
    cout << "Enter the data (-1 for no node): ";
    int data;
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    root = new Node(data);
    cout << "Enter data for the left side of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for the right side of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
int main(){
    Node *root=NULL;
    root=buildTree(root);
}