#include<iostream>
using namespace std;
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;
void push1(int data){
    if(top1==N-1){
        cout<<"Overflow"<<endl;
    }
    else {
        top1++;
        s1[top1]=data;
    }
}

void push2(int data){
    if(top2==N-1){
        cout<<"Overflow"<<endl;
    }
    else {
        top2++;
        s2[top2]=data;
    }
}
int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}
void display(){
    for(int i=0;i<=top1;i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
}
void enqueue(int x){
    push1(x);
    count++;
}
void dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        cout<<"queue is empty"<<endl;
    }
    else {
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        cout<<"element poped is:"<<b<<endl;
        count--;
        for(i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}
int main(){
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();
    enqueue(7);
    display();
    return 0;
}