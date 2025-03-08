#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node* findMin(Node *root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node * deleteNode(Node *root,int value){
        if(root==NULL){
            return root;
        }
        if(root->data==value){
            // 0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // 1 child

            //left child
            if(root->left!=NULL && root->right==NULL){
                Node *temp=root->left;
                delete root;
                return temp;
            }
            // right child
            if(root->left==NULL && root->right!=NULL){
                Node *temp=root->right;
                delete root;
                return temp;
            }
            //2 child
            if(root->left!=NULL && root->right!=NULL){
                int min_val=findMin(root->right)->data;
                root->data=min_val;
                root->right=deleteNode(root->right,min_val);
            }
        }
        else if(root->data>value){
            root->left=deleteNode(root->left,value);
        }
        else{
            root->right=deleteNode(root->right,value);
        }
}
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
Node* insert(Node *root,int value){
    if(root==NULL){
        return new Node(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
int main(){
    Node *root=NULL;
    root=insert(root,11);
    insert(root,6);
    insert(root,19);
    insert(root,4);
    insert(root,8);
    insert(root,17);
    insert(root,43);
    insert(root,5);
    insert(root,10);
    insert(root,31);
    insert(root,49);
    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;
    root=deleteNode(root,11);
    cout << "Inorder traversal after deleting 11: ";
    inorderTraversal(root);
    cout << endl;
    
}