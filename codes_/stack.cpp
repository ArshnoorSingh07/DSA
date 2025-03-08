#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top=-1;
void push(){
    int x;
    cout<<"Enter the data :";
    cin>>x;
    if(top==N-1){
        cout<<"Overflow"<<endl;
    }
    else {
        top++;
        stack[top]=x;
    }

}
void pop(){
    int item;
    if(top==-1){
        cout<<"Underflow"<<endl;
    }
    else {
        item=stack[top];
        top--;
        cout<<item<<" "<<"is poped"<<endl;
    }
}
void peek(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
    }
    else {
        cout<<"top elemenst is "<<stack[top]<<endl;
    }
}
void display(){
    cout<<"stack elements are"<<endl;
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<endl;
    }
}
int main(){
    int ch;
    do {
        cout<<"press 1:push()\npress 2:pop()\npress 3:peek()\npress 4:display()\n";
        cin>>ch;
        switch(ch) {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default :
            cout<<"Invalid choice"<<endl;
        }
    }while(ch!=0);

    return 0;
}

