#include <iostream>
using namespace std;

class Queue {
    char arr[100];
    int front, rear, size;
public:
    Queue(){front = 0; rear = -1; size = 0;}

    bool isEmpty(){return size == 0;}
    bool isFull(){return size == 100;}

    void enqueue(char x){
        if (isFull()) return;
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    void dequeue(){
        if (isEmpty()) return;
        front = (front + 1) % 100;
        size--;
    }

    char peek(){
        if (isEmpty()) return '#';  
        return arr[front];
    }

    int getSize(){return size;}
};

void first(string s){
    Queue q;
    int freq[256] = {0}; 

    for (int i = 0; i < s.length(); i++){
        char ch = s[i];
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek()] > 1){
            q.dequeue();
        }

        if (q.isEmpty()) cout<< -1 <<" ";
        else cout<< q.peek() <<" ";
    }
    cout<<endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    first(s);
    return 0;
}
