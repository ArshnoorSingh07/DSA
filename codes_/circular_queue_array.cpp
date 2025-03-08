//circular Queue ;
#include<iostream>
using namespace std;
#define N 5
int queue[N];
int rear=-1,front=-1;
void enqueue(int x)
{
	if(rear==-1 && front==-1)
	{
		rear=front=0;
		queue[rear]=x;
	}
	else if((rear+1)%N==front)
	{
		cout<<"Queue is Full.";
	}
	else
	{
		rear=(rear+1)%N;
		queue[rear]=x;
	}
}
void dequeue()
{
    if(rear==-1&&front==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(rear==front)
    {
        rear=front=-1;
    }
    else
    {
        cout<<"dequeued element is : "<<queue[front];
        front=(front+1)%N;
    }
}
void display()
{
    if(rear==-1 && front==-1)
    {
        cout<<"Queue is empty";
    }
    else 
    {
        int i=front;
        while(i!=rear)
        {
            cout<<queue[i]<<" ";
            i=(i+1)%N;
        }
        cout<<queue[rear];
    }
}
int main()
{
enqueue(5);
enqueue(6);
enqueue(8);
enqueue(9);
enqueue(10);
dequeue();
dequeue();
dequeue();
enqueue(1);
display();
}