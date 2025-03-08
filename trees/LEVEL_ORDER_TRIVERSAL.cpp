#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node* root) {
    if (root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left!=NULL) {
            q.push(temp->left);
        }
        if (temp->right!=NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node *root = nullptr;
    root = buildTree(root);
    cout << "\nLevel-order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
