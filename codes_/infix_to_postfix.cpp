#include<iostream>
#include<string>
using namespace std;
#define N 100

class Stack{
public:
    char stack[N];
    int top = -1;

    void push(char x) {
        if(top == N-1) cout << "Overflow" << endl;
        else {
            top++;
            stack[top] = x;
        }
    }

    void pop() {
        if(top == -1) cout << "Underflow" << endl;
        else {
            cout << stack[top] << " is popped" << endl;
            top--;
        }
    }

    char peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return '\0';
        } else return stack[top];
    }

    bool isempty() {
        return top == -1;
    }

    void display() {
        for(int i = top; i >= 0; i--) cout << stack[i] << endl;
    }

    int precedence(char ch) {
        if(ch == '+' || ch == '-') return 1;
        else if(ch == '*' || ch == '/') return 2;
        else if(ch == '^') return 3;
        return 0;
    }

    void infixtopostfix(string s) {
        string ans;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            ans += ch;
            }
            else if(ch == '('){
            push(ch);
        }
            else if(ch == ')') {
                while(!isempty() && peek() != '(') {
                    ans += peek();
                    pop();
                }
                pop();
            } else {
                while(!isempty() && precedence(peek()) >= precedence(ch)) {
                    ans += peek();
                    pop();
                }
                push(ch);
            }
        }
        while(!isempty()) {
            ans += peek();
            pop();
        }
        cout << "Postfix expression: " << ans << endl;
    }
};

int main() {
    Stack a;
    string infix;
    cin >> infix;
    a.infixtopostfix(infix);
    return 0;
}
