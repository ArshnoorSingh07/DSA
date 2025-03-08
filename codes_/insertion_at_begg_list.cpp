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
class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void insertatbegg(int value){
        Node *nextnode = new Node(value);
        if(head==nullptr){
            head=nextnode;
            return;
        }
        else{
            nextnode->next=head;
            head=nextnode;
        }
    }
    void insertend(int data)
    {
        Node* newnode=new Node(data);
        if(head==nullptr){
            head=newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void display(){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        temp->next=head;
    }

};
int main(){
    LinkedList list;
    list.insertatbegg(0);
    list.insertatbegg(100);
    list.display();
    return 0;
}
