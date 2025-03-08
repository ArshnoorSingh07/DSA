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
class Linkedlist{
    Node *head;
    public:
    Linkedlist(){
        head=nullptr;
    }
    void insertdata(int value){
        Node *newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
        }
        else {
            Node *temp = head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
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
    int choice=1;
    while(choice){
        int data;
        cout<<"Enter the data of the list:";
        cin>>data;
        list.insertdata(data);
        cout<<"Do you want to continue(0,1):";
        cin>>choice;
    }
    cout<<"Linkedlist:";
    list.display();
}