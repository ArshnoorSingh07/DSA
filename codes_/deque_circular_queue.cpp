#include<iostream>
using namespace std;
#define N 5
int deque[N];
int f = -1, r = -1;

void enqueuefront(int x) {
    if ((f == 0 && r == N - 1) || (f == r + 1)) {
        cout << "deque is full" << endl;
    }
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0) {
        f = N - 1;
        deque[f] = x;
    }
    else {
        f--;
        deque[f] = x;
    }
}

void enqueuerear(int x) {
    if ((f == 0 && r == N - 1) || (f == r + 1)) {
        cout << "deque is full" << endl;
    }
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[r] = x;
    }
    else if (r == N - 1) {
        r = 0;
        deque[r] = x;
    }
    else {
        r++;
        deque[r] = x;
    }
}

void dequefront() {
    if (f == -1 && r == -1) {
        cout << "deque is empty" << endl;
    }
    else if (f == r) {
        cout << "dequeued element is: " << deque[f] << endl;
        f = r = -1;
    }
    else if (f == N - 1) {
        cout << "dequeued element is: " << deque[f] << endl;
        f = 0;
    }
    else {
        cout << "dequeued element is: " << deque[f] << endl;
        f++;
    }
}

void dequerear() {
    if (f == -1 && r == -1) {
        cout << "deque is empty" << endl;
    }
    else if (f == r) {
        cout << "dequeued element is: " << deque[r] << endl;
        f = r = -1;
    }
    else if (r == 0) {
        cout << "dequeued element is: " << deque[r] << endl;
        r = N - 1;
    }
    else {
        cout << "dequeued element is: " << deque[r] << endl;
        r--;
    }
}

void display() {
    if (f == -1) {
        cout << "deque is empty" << endl;
        return;
    }
    int i = f;
    while (i != r) {
        cout << deque[i] << " ";
        i = (i + 1) % N;
    }
    cout << deque[r] << endl;
}

int main() {
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    dequefront();
    dequerear();
    dequefront();
    display();

    return 0;
}
