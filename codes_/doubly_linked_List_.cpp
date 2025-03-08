#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
    Node *head;
    public:
    DoublyLinkedList(){
        head=NULL;
    }
    void InsertAtBegg(int value){
        Node *newnode = new Node(value);
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    void InsertAtEnd(int value){
        Node *newnode = new Node(value);
        if(head==NULL){
            head=newnode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
    void display(){
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void DeleteFromBegg(){
        if(head==NULL){
            return;
        }
        Node *temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        delete temp;
    }
    void DeleteFromEnd(){
        if(head==NULL){
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->prev!=NULL){
            temp->prev->next=NULL;
        }
        else{
            head=NULL;
        }
        delete temp;
    }
};
int main(){
    DoublyLinkedList dll;
    dll.InsertAtBegg(2);
    dll.InsertAtBegg(1);
    dll.InsertAtBegg(100);
    dll.InsertAtEnd(-100);
    dll.InsertAtEnd(0);
    dll.DeleteFromBegg();
    dll.DeleteFromEnd();
    dll.display();
}