#include <iostream>
using namespace std;

class circularQ{
    int arr[5];
    int front, rear;
public:
    circularQ(){ 
        front = -1; rear = -1; 
    }

    bool isEmpty(){return (front == -1);}
    bool isFull(){return ((rear + 1) % 5 == front);}

    void enqueue(int x){
        if (isFull()) {cout<<"Queue Full"<<endl;}
        if (isEmpty()) front = 0;
        rear = (rear + 1) % 5;
        arr[rear] = x;
    }

    void dequeue(){
        if (isEmpty()) {cout<<"Queue Empty"<<endl;}
        cout<<"Dequeued: "<<arr[front]<<endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
    }

    void peek() {
        if (!isEmpty()) cout<<"Front Element: "<<arr[front]<<endl;
        else cout<<"Queue Empty"<<endl;
    }

    void display() {
        if (isEmpty()){cout<<"Queue Empty"<<endl;}
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main() {
    circularQ cq;
    int choice, val;
    do {
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit"<<endl;
        cin >> choice;
        switch(choice){
        case 1: cout<<"Enter value:";
        cin>>val; 
        cq.enqueue(val); 
        break;
        case 2: cq.dequeue(); 
        break;
        case 3: cq.display(); 
        break;
        case 4: cq.peek(); 
        break;
        }
    } while (choice != 5);
}
