#include <iostream>
using namespace std;


int stack[5]; 
int top = -1;

// Function to check if stack is full
bool isFull() {
    return top == 5 - 1;
}

// Function to check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Push operation
void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        stack[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

// Pop operation
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
    } else {
        cout << stack[top--] << " popped from stack." << endl;
    }
}

// Peek operation
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Display all elements
void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout <<"--- Menu ---"<<endl;
        cout << "1. Push\n 2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value to push: "; cin >> value; push(value); break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl; break;
            case 4: cout << (isFull() ? "Stack is Full" : "Stack is not Full") << endl; break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exit"; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 7);

    return 0;
}
