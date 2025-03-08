#include<iostream>
#include<string>
using namespace std;
#define N 100

class Stack{
public:
    string stack[N];
    int top = -1;

    void push(string x) {
        if(top == N-1) cout << "Overflow" << endl;
        else {
            top++;
            stack[top] = x;
        }
    }

    void pop() {
        if(top == -1) cout << "Underflow" << endl;
        else top--;
    }

    string peek() {
        if(top == -1) return "";
        else return stack[top];
    }

    bool isempty() {
        return top == -1;
    }

    void postfixtoinfix(string s) {
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                string op(1, ch); // convert char to string
                push(op);
            }
            else {
                string op1 = peek(); pop();
                string op2 = peek(); pop();
                string expr = "(" + op2 + ch + op1 + ")";
                push(expr);
            }
        }

        cout << "Infix expression: " << peek() << endl;
    }
};

int main() {
    Stack a;
    string postfix;
    cin >> postfix;
    a.postfixtoinfix(postfix);
    return 0;
}
