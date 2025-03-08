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
class Stack{
    Node *top;
    public:
    Stack(){
        top=nullptr;
    }
    void push(int value){
        Node *newnode = new Node(value);
        newnode->next = top;
        top=newnode;
        cout<<value<<" is pushed"<<endl;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else {
            Node *temp = top;
            int popped = temp->data;
            top = top->next;
            delete temp;
            return popped;
        }
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else {
            return top->data;
        }
    }
    bool isEmpty(){
        return top==nullptr;
    }
    void display(){
        if (isEmpty()) {
            cout<<"Stack is empty."<<endl;
            return;
        }

        Node* temp = top;
        cout<<"Stack elements: ";
        while (temp!=nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout<<"Top element is: "<<stack.peek()<<endl;

    cout<<stack.pop()<<" popped from stack."<<endl;
    stack.display();
    return 0;
}