#include <iostream>
using namespace std;
#define MAX 100
class stack{
    int arr[MAX], top;
public:
    stack(){
        top = -1;
    }
    void push(int x){
        if (top == MAX - 1) {
            cout<<"Stack Overflow"<<endl;
        } else{
            top++;
            arr[top] = x;
            cout<<x<<" pushed into stack"<<endl;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow!"<<endl;
        } else{
            cout<<arr[top]<<" popped from stack"<<endl;
            top = top-1;
        }
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == MAX - 1);
    }
    void peek(){
        if (top == -1){
            cout << "Stack is Empty!\n";
        } else{
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display(){
        if (top == -1){
            cout << "Stack is Empty!\n";
        } else {
            cout<<"Stack elements are: ";
            for(int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout<<endl;
        }
    }
};
int main(){
    stack st;
    int choice, val;
    do{
        cout << "Menu" <<endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            st.display();
            break;
        case 5:
            cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
            break;
        case 6:
            cout << (st.isFull() ? "Stack is Full\n" : "Stack is Not Full\n");
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while(choice != 7);
    return 0;
}
