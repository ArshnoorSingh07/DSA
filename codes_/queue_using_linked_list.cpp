#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data=value;
        next=nullptr;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front=nullptr;
        rear=nullptr;
    }

    void enqueue(int value) {
        Node* newNode=new Node(value);

        if(rear==nullptr) {
            front=rear=newNode;
            cout<<value<<" enqueued to the queue."<<endl;
            return;
        }
        rear->next=newNode;
        rear=newNode;

        cout<<value<<" enqueued to the queue."<<endl;
    }

    int dequeue() {
        if(front==nullptr) {
            cout<<"Queue underflow! No elements to dequeue."<<endl;
            return -1;
        }
        Node* temp=front;
        int dequeuedValue=temp->data;
        front=front->next;

        if(front==nullptr) {
            rear=nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Queue is empty."<<endl;
            return -1;
        } else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front==nullptr;
    }

    void display() {
        if(isEmpty()) {
            cout<<"Queue is empty."<<endl;
            return;
        }

        Node* temp=front;
        cout<<"Queue elements: ";
        while(temp!=nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue queue;

    int choice=1;
    while(choice) {
        int value;
        cout<<"Enter value to enqueue: ";
        cin>>value;
        queue.enqueue(value);

        cout<<"Do you want to continue (0/1)? ";
        cin>>choice;
    }

    queue.display();

    cout<<"Do you want to dequeue (0/1)? ";
    cin>>choice;
    if(choice==1) {
        cout<<queue.dequeue()<<" dequeued from queue."<<endl;
        queue.display();
    }

    cout<<"Front element is: "<<queue.peek()<<endl;

    return 0;
}
