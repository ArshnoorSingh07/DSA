#include<iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x){
    if(rear==N-1){
        cout<<"overflow condition"<<endl;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else {
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"empty queue"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else {
        cout<<"you deleted:"<<queue[front]<<endl;
        front++;
    }
}
void peek(){
   if(front==-1 && rear==-1){
        cout<<"empty queue"<<endl;
    }
    else {
        cout<<"peek element is:"<<queue[front]<<endl;
    }
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"empty queue"<<endl;
    }
    else {
        for(int i=front;i<rear+1;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    enqueue(1);
    enqueue(12);
    enqueue(11);
    enqueue(18);
    display();
    dequeue();
    dequeue();
    peek();
    display();
}