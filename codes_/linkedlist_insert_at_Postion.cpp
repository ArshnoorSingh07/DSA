#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};
class Linkledlist{
    Node *head;
    public:
    Linkledlist(){
        head=nullptr;
    }
    public:
    void insertatpos(int value,int pos){
        Node *newnode = new Node(value);
        if(pos==1){
            newnode->next=head;
            head=newnode;
            return;
        }
        Node *temp = head;
        int i=1;
        while(i < pos-1){
            temp=temp->next;
            i++;
        }
        if(temp==nullptr){
            cout<<"empty"<<endl;
            return;
        }
        newnode->next=temp->next; 
        temp->next = newnode;
    }
    void display(){
        Node *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Linkledlist list;
    int choice = 1;
    while(choice){
        int data,pos;
        cout<<"Enter the data:";
        cin>>data;
        cout<<"Enter the position:";
        cin>>pos;
        list.insertatpos(data,pos);
        cout<<"Do you want to insert more nodes? (0 for No, 1 for Yes):";
        cin>>choice;
    }
    cout<<"Linked list:";
    list.display();
    return 0;
}