#include <iostream>
#include <string>
using namespace std;


char stackArr[100];
int top = -1;

void push(char c) {
    stackArr[++top] = c;
}

char pop() {
    return stackArr[top--];
}

int main() {
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
