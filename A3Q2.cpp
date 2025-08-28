#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
class Stack{
    char arr[MAX];
    int top;
public:
    Stack(){ top = -1; }
    void push(char c){
        if(top == MAX - 1){
            cout<<"Stack Overflow!";
        } else{
            arr[++top] = c;
        }
    }
    char pop(){
        if (top == -1){
            return '\0';
        } else {
            return arr[top--];
        }
    }
    bool isEmpty(){
        return (top == -1);
    }
};
int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin>>str;
    Stack st;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        st.push(str[i]);
    }
    cout << "Reversed string: ";
    while(!st.isEmpty()){
        cout << st.pop();
    }
    cout<<endl;
    return 0;
}
