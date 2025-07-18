#include <iostream>
using namespace std;
// Insert, Remove, PeekFront, size, isEmpty, isFull
class Queue {
    private:
        int number[10];
        int front; //store index of front element
        int rear; // store index of the rear/back/end element
    public:
        void insert(int values); //insert an element at the rear or back
        void multiInsert(int values[], int count);
        void remove(); // remove the front element
        int peekFront(); // return value of the front element
        int QueueSize(); // return number of the element
        bool isEmpty();
        bool isFull();
        void Initialize();
        void printQueue();
};

// Initializes the queue
void Queue::Initialize() {
    rear = front = -1;
}

// Inserting a Single Element
void Queue::insert(int value){
    if (isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1) front = 0;  // Set front when inserting the first element
    number[++rear] = value;
}

// Inserting Multiple Elements
void Queue::multiInsert(int values[], int count) {
    for (int i = 0; i < count; i++) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert more elements." << endl;
            break;
        }
        if (front == -1) {
            front = 0; // Only set when queue was empty
        }
        rear++;
        number[rear] = values[i];
    }
}

// Remove the first element
void Queue::remove() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "The value " << number[front] << " is removed" << endl;
    front++;
    if (front > rear) { // Reset queue when empty
        front = rear = -1;
    }
}

// Print the first element
int Queue::peekFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return number[front];
}

// Get the size of the queue
int Queue::QueueSize() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return front == -1 || front > rear;
}

// Check if the queue is full
bool Queue::isFull() {
    return rear == 9;
}

// For Printing Queues
void Queue::printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << number[i] << " ";
        }
        cout << endl;
    }
}

Queue Q1;

void ui() {
    cout << "==================================" << endl;
    cout << "1. Insert an element" << endl;
    cout << "2. Insert multi elements" << endl;
    cout << "3. Remove an element" << endl;
    cout << "4. Peek the queue" << endl;
    cout << "5. Check size of queue" << endl;
    cout << "6. Check if queue is empty" << endl;
    cout << "7. Check if queue is full" << endl;
    cout << "0. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1:
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            Q1.insert(value);
            Q1.printQueue();
            break;

        case 2: {
            int count;
            cout << "Enter the number of elements to insert: ";
            cin >> count;
            
            // Validate the number of elements
            if (count > 10 || count < 1) {
                cout << "Invalid count. Maximum queue size is 10." << endl;
                break;
            }
            
            int* values = new int[count]; // Dynamic Memory Allocation
            
            cout << "Enter the values: ";
            for (int i = 0; i < count; i++) {
                cin >> values[i];
            }

            Q1.multiInsert(values, count);
            delete[] values; // Free memory or advoid memory leaks
            Q1.printQueue();
            break;
        }
        case 3:
            Q1.remove();
            Q1.printQueue();
            break;
        case 4:
            int frontValue;
            frontValue = Q1.peekFront();
            if (frontValue != -1) {
                cout << "The value at the front is " << frontValue << endl;
            }
            break;
        case 5:
            cout << "The size of the queue is " << Q1.QueueSize() << endl;
            break;
        case 6:
            cout << (Q1.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 7:
            cout << (Q1.isFull() ? "Queue is full" : "Queue is not full") << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

int main() {
    Q1.Initialize();
    while (true) {
        ui();
    }
    return 0;
}
