#include <iostream>
#include <cstring>  // For strlen()
#include <cstdlib>  // For atoi()

using namespace std;

#define MAX 100

int top = -1;  // Top of the stack

// Stack class to handle operands (numbers)
class Stack {
    int arr[MAX];  // Stack to store operands

public:
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if the character is an operand (digit)
bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    Stack s;

    for (int i = 0; i < strlen(postfix); i++) {
        // If the character is an operand (number), push it to the stack
        if (isOperand(postfix[i])) {
            s.push(postfix[i] - '0');  // Convert char digit to int
        }
        // If the character is an operator, pop two elements from the stack, perform the operation, and push the result
        else {
            int operand2 = s.pop();
            int operand1 = s.pop();

            switch (postfix[i]) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }

    // The final result will be the only element in the stack
    return s.pop();
}

int main() {
    char postfix[MAX];

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of postfix evaluation: " << result << endl;

    return 0;
}
