#include<iostream>
#include<stack>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* Buildtree(Node *root) {
    cout << "Enter the data (or -1 for null): ";
    int data;
    cin >> data;
    
    if(data == -1) {
        return NULL;
    }
    
    root = new Node(data);
    
    cout << "Enter data for the left side of " << data << endl;
    root->left = Buildtree(root->left);
    
    cout << "Enter data for the right side of " << data << endl;
    root->right = Buildtree(root->right);
    cout << endl;
    
    return root;
}

void inorderTraversal(Node *root) {
    if(root == NULL) return;
    
    stack<Node*> s;
    Node *current = root;
    
    cout << "Inorder: ";
    while(current != NULL || !s.empty()) {
        while(current != NULL) {
            s.push(current);
            current = current->left;
        }
        
        current = s.top();
        s.pop();
        
        cout << current->data << " ";
        
        current = current->right;
    }
    cout << endl;
}

void preorderTraversal(Node *root) {
    if(root == NULL) return;
    
    stack<Node*> s;
    s.push(root);
    
    cout << "Preorder: ";
    while(!s.empty()) {
        Node *current = s.top();
        s.pop();
        
        cout << current->data << " ";
        
        if(current->right) {
            s.push(current->right);
        }
        if(current->left) {
            s.push(current->left);
        }
    }
    cout << endl;
}

void postorderTraversal(Node *root) {
    if(root == NULL) return;
    
    stack<Node*> s1, s2;
    s1.push(root);
    
    cout << "Postorder: ";
    while(!s1.empty()) {
        Node *current = s1.top();
        s1.pop();
        
        s2.push(current);
        
        if(current->left) {
            s1.push(current->left);
        }
        if(current->right) {
            s1.push(current->right);
        }
    }
    
    while(!s2.empty()) {
        Node *current = s2.top();
        s2.pop();
        
        cout << current->data << " ";
    }
    cout << endl;
}

int main() {
    Node *root = NULL;
    root = Buildtree(root);
    
    inorderTraversal(root);
    preorderTraversal(root);
    postorderTraversal(root);
    
    return 0;
}
