#include <iostream>
#include <stack>
#include <string>
using namespace std;
int evaluatePostfix(string postfix){
    stack<int> st;
    for(int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9'){
            st.push(c - '0');
        }
        else{
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = 0;
            if (c == '+') result = val1 + val2;
            else if (c == '-') result = val1 - val2;
            else if (c == '*') result = val1 * val2;
            else if (c == '/') result = val1 / val2;
            st.push(result);
        }
    }
    return st.top();
}
int main(){
    string postfix;
    cout<<"enter a Postfix expression (single-digit operands): ";
    getline(cin, postfix);
    int result = evaluatePostfix(postfix);
    cout<<"result: "<<result<<endl;
    return 0;
}
