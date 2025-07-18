#include <iostream>
using namespace std;
// Insert, Remove, PeekFront, size, isEmpty, isFull
class MyQueue{
    private:
        int A[10];
        int rear;
        int front;
    public:
        void InitializeQueue();
        void Insert(int Value); // Insert an element at the front
        void Remove(); // Remove the front element
        int PeekFront(); // Peek the front element
        int QueueSize(); // Number of elements
        bool isEmpty();
        bool isFull();
        void PrintQueue();
};

void MyQueue::InitializeQueue() {
    rear = front = -1;
};

void MyQueue::Insert(int Value) {
    // Check is queue full

    // Queue is empty
    if ( rear == -1 && front == -1 ){
        rear = front = 0;
        A[ rear ] = Value;
    }
    else {
        rear++;
        A[ rear ] = Value;
    }
};

void MyQueue::PrintQueue() {
    //check if queue is empty
    for ( int i = 0; i <= rear; i++ ){
        cout << A[i] << " ";
    }
};

// Print the first element
int MyQueue::PeekFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return A[front];
}

int MyQueue::QueueSize() {
    if ( isEmpty() ){
        return 0;
    }
    return rear - front + 1;
};

bool MyQueue::isEmpty() {
    return ( rear == -1 && front == -1 );
};

bool MyQueue::isFull() {
    return ( rear == 9 );
};

void MyQueue::Remove() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "The value " << A[front] << " is removed" << endl;
    front++;
    if (front > rear) { // Reset queue when empty
        front = rear = -1;
    }
};

int main()
{
    MyQueue Q1;
    Q1.InitializeQueue();
    Q1.Insert(10);
    Q1.Insert(20);
    Q1.Insert(30);
    Q1.PrintQueue();
    cout << endl;
    cout << Q1.PeekFront() << endl;
    Q1.Remove();
    Q1.PrintQueue();
    cout << endl;
    cout << Q1.QueueSize() << endl;
    cout << Q1.isEmpty() << endl;
    cout << Q1.isFull() << endl;

    return 0;
}