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
void inOrderTriversal(Node *root){
    if(root!=NULL){
        inOrderTriversal(root->left);
        cout<<root->data<<" ";
        inOrderTriversal(root->right);
    }
}
int main(){
    Node *root=NULL;
    root=insert(root,8);
    insert(root,3);
    insert(root,10);
    insert(root,1);
    insert(root,6);
    insert(root,14);
    insert(root,4);
    insert(root,73);
    cout<<"Inorder Triversal:";
    inOrderTriversal(root);
    cout<<endl;
    return 0;
}