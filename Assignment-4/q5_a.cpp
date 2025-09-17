#include <iostream>
using namespace std;

class Queue{
    int arr[100];
    int front, rear, size;
public:
    Queue(){front = 0; rear = -1; size = 0;}

    bool isEmpty(){return size == 0;}
    bool isFull(){return size == 100;}

    void enqueue(int x){
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

    int peek(){
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getSize(){return size;}
};

class StackTwo{
    Queue q1, q2;
public:
    void push(int x){
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        if (!q1.isEmpty()) q1.dequeue();
        else cout << "Stack Empty"<<endl;
    }

    int top(){
        if (!q1.isEmpty()) return q1.peek();
        return -1;
    }

    bool empty(){ return q1.isEmpty();}
};

int main() {
    StackTwo s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<"Top (Two Queues): "<<s1.top()<<endl;
    s1.pop();
    cout<<"Top after pop: "<<s1.top()<<endl;
}