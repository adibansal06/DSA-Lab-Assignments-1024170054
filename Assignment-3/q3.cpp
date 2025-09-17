#include <iostream>
using namespace std;

class queue{
    int arr[100];
    int front, rear, size;
public:
    queue(){
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {return size == 0;}
    bool isFull() {return size == 100;}

    void enqueue(int x){
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % 100;
        size--;
    }

    int peek(){
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getSize(){ return size; }
};

void interleave(queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    int half = n / 2;
    queue firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.peek());
        q.dequeue();
    }

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.peek());
        firstHalf.dequeue();

        q.enqueue(q.peek());
        q.dequeue();
    }
}

int main() {
    queue q;
    int n, x;

    cout<<"Enter number of elements (even): ";
    cin>>n;

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin>>x;
        q.enqueue(x);
    }

    interleave(q);

    cout<<"Output: ";
    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }
    cout << endl;

    return 0;
}
