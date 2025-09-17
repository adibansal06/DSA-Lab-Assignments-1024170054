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

class StackOne{
    Queue q;
public:
    void push(int x){
        q.enqueue(x);
        int sz = q.getSize();
        for (int i = 0; i < sz - 1; i++) {
            q.enqueue(q.peek());
            q.dequeue();
        }
    }

    void pop(){
        if (!q.isEmpty()) q.dequeue();
        else cout<<"Stack Empty"<<endl;
    }

    int top(){
        if (!q.isEmpty()) return q.peek();
        return -1;
    }

    bool empty(){return q.isEmpty();}
};

int main(){
StackOne s2;
    s2.push(5);
    s2.push(15);
    cout<<"Top (One Queue): "<<s2.top()<<endl;
    s2.pop();
    cout<<"Top after pop: "<<s2.top()<<endl;
}
