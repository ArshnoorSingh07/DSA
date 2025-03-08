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
        else top--;
    }

    char peek() {
        if(top == -1) return '\0';
        else return stack[top];
    }

    bool isempty() {
        return top == -1;
    }

    int precedence(char ch) {
        if(ch == '+' || ch == '-') return 1;
        else if(ch == '*' || ch == '/') return 2;
        else if(ch == '^') return 3;
        return 0;
    }

    string reverseString(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
        return s;
    }

    void infixtoprefix(string s) {
        s = reverseString(s);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';
        }

        string ans;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                ans += ch;
            } 
            else if(ch == '(') {
                push(ch);
            } 
            else if(ch == ')') {
                while(!isempty() && peek() != '(') {
                    ans += peek();
                    pop();
                }
                pop();  // Pop the '(' from the stack
            } 
            else {
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

        ans = reverseString(ans);
        cout << "Prefix expression: " << ans << endl;
    }
};

int main() {
    Stack a;
    string infix;
    cin >> infix;
    a.infixtoprefix(infix);
    return 0;
}
