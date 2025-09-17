#include <iostream>
using namespace std;


int stackArr[100];
int top = -1;

void push(int x) {
     stackArr[++top] = x; 
    }

int pop() {
     return stackArr[top--]; 
    }

int postFix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else {
            int a = pop();
            int b = pop();
            switch (c) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[100];
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result: " << postFix(exp) << endl;
    return 0;
}
