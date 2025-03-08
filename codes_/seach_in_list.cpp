#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    public:
    Node(int value){
        data=value;
        next=nullptr;
    }
};
class Linkedlist{
    Node *head;
    public:
    Linkedlist(){
        head=nullptr;
    }
    void insert(int value){
        Node *newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
        }
        else {
            Node *temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    bool search(int val){
        Node *temp = head;
        while(temp!=nullptr){
            if(temp->data==val){
                return 1;
            }
            temp=temp->next;
        }
        return 0;
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
    Linkedlist list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.display();
    if(list.search(4)){
        cout<<"found"<<endl;
    }
    else {
        cout<<"Not found"<<endl;
    }
    return 0;
}