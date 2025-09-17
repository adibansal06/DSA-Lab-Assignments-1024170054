#include <iostream>
using namespace std;

class Queue{
    int arr[5];
    int front, rear;
public:
    Queue(){ front = -1; rear = -1; }

    bool isEmpty(){ return (front == -1 && rear == -1);}
    bool isFull(){ return (rear == 5 - 1);}

    void enqueue(int x){
        if (isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    void dequeue(){
        if (isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Dequeued: "<<arr[front]<<endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek(){
        if (!isEmpty()) cout<<"Front Element: "<<arr[front]<<endl;
        else cout<<"Queue Empty"<<endl;
    }

    void display(){
        if (isEmpty()){cout<<"Queue Empty"<<endl;}
        cout<<"Queue: "<<endl;
        for (int i = front; i <= rear; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Queue q;
    int choice, val;
    do {
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit"<<endl;
        cin>>choice;
        switch (choice) {
        case 1: cout<<"Enter value: "; 
        cin >> val; 
        q.enqueue(val);
        break;
        case 2: q.dequeue(); 
        break;
        case 3: q.display(); 
        break;
        case 4: q.peek(); 
        break;
        }
    } while (choice != 5);
    return 0;
}
