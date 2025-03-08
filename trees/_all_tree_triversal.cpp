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
Node* Buildtree(Node *root){
    cout<<"Enter the data(or -1 for null):";
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root= new Node(data);
    cout << "Enter data for the left side of " << data << endl;
    root->left = Buildtree(root->left);

    cout << "Enter data for the right side of " << data << endl;
    root->right = Buildtree(root->right);
    cout<<endl;

    return root;
}
void inorderTriversal(Node *root){
    if(root==NULL){
        return;
    }
    inorderTriversal(root->left);
    cout<<root->data<<" ";
    inorderTriversal(root->right);
}
void preorderTriversal(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTriversal(root->left);
    preorderTriversal(root->right);
}
void postorderTriversal(Node *root){
    if(root==NULL){
        return;
    }
    postorderTriversal(root->left);
    postorderTriversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node *root=NULL;
    root=Buildtree(root);
    cout<<"Inorder:";
    inorderTriversal(root);
    cout<<endl;
    cout<<"preorder:";
    preorderTriversal(root);
    cout<<endl;
    cout<<"postorder:";
    postorderTriversal(root);
}