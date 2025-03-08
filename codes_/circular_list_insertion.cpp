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
    void insertatpos(int value,int pos){
        Node *newnode = new Node(value);
        if(pos==1){
            if(head==nullptr){
                head=newnode;
                newnode->next=head;
            }
            else{
                Node *temp=head;
                while(temp->next!=head){
                    temp=temp->next;
                }
                newnode->next=head;
                temp->next=newnode;
                head=newnode;
            }
        }
        else{
            Node *temp=head;
            int count=1;
            while(count<pos-1 && temp->next!=head){
                temp=temp->next;
                count++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
        void display() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }

        Node *temp = head;
        cout << "Linked list: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // Stop when we reach back to the head
        cout << endl;
    }
};
int main() {
    Linkedlist list;
    int choice = 1;

    while (choice) {
        int data, position;
        cout << "Enter the data of the list: ";
        cin >> data;
        cout << "Enter the position where to insert: ";
        cin >> position;
        list.insertatpos(data, position);
        cout << "Do you want to continue (0, 1): ";
        cin >> choice;
    }

    // Display the final circular linked list
    cout << "Linked list: ";
    list.display();

    return 0;
}
