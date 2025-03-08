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
    void insertdataincircular(int value){
        Node *newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
            newnode->next=head; // this is the condition
        }
        else{
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head; // add this thing
        }
    }
    void display(){
        if(head==nullptr){
            cout<<"Empty list:"<<endl;
        }
        Node *temp=head;
        cout<<"Linled list:";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
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
        list.insertdataincircular(data);
        cout<<"Do you want to continue(0,1):";
        cin>>choice;
    }
    cout<<"Linkedlist:";
    list.display();
    return 0;
}