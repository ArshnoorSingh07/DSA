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
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deletenode(int pos){
        if(head==nullptr){
            cout<<"list is empty:"<<endl;
        }
        Node *temp = head;
        if(pos==1){
            head=temp->next;
            delete temp;
        }
        for(int i=1;temp!=nullptr && i<pos-1;i++){
            temp = temp->next;
        }
        if(temp==nullptr || temp->next==nullptr){
            cout<<"Bound error!!!!"<<endl;
        }
        Node *nodetodelete = temp->next;
        temp->next = nodetodelete->next;
        delete nodetodelete;
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
    cout<<"Linked list:";
    list.display();
    cout<<endl;
    choice=1;
    while(choice){
        int pos;
        cout<<"Enter the position to delete:";
        cin>>pos;
        list.deletenode(pos);
        cout<<"Do you want to continue to delete(0,1):";
        cin>>choice;
    }
    cout<<"Linked list:";
    list.display();
    return 0;
}