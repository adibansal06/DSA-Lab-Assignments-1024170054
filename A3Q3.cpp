#include <iostream>
using namespace std;
#define max 100
class stack{
    char arr[max];
    int top;
public:
    stack(){ top = -1; }
    void push(char c){ arr[++top] = c; }
    char pop(){
        if (top == -1) return '\0';
        return arr[top--];
    }
    bool isEmpty(){ return (top == -1); }
};
bool isBalanced(char exp[]){
    stack st;
    for(int i = 0; exp[i] != '\0'; i++){
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) return false;
            char top = st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}
int main(){
    char exp[100];
    cout<<"enter expression: ";
    cin>>exp;
    if(isBalanced(exp))
        cout<<"balanced expression"<<endl;
    else
        cout<<" not balanced parenthesis";
    return 0;
}

