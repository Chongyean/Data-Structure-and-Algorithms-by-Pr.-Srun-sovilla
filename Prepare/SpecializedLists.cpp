#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;


// LIFO (Last In First Out) principle.
void Stack() {
    stack<int> s;

    // Pushing elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Displaying the top element
    cout << "Top element: " << s.top() << endl;

    // Pop two elements
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    s.pop();

    // Checking size and empty status
    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
}

// FIFO (First In First Out) principle.
void Queue() {
    queue<int> q;

    // Pushing elements
    q.push(1);
    q.push(2);
    q.push(3);

    // Display front and back
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;

    // Pop two elements
    q.pop();
    cout << "Front after pop: " << q.front() << endl;
    q.pop();

    // Checking size and empty status
    cout << "Queue size: " << q.size() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
}

// Priority Queue is a container that follows the property.
void PriorityQueue() {
    // Max- (default)
    priority_queue<int> max;

    // Min- using greater<>
    priority_queue<int, vector<int>, greater<int>> min;

    // Inserting elements
    max.push(10);
    max.push(20);
    max.push(5);

    min.push(10);
    min.push(20);
    min.push(5);

    // Displaying top elements
    cout << "Max - top: " << max.top() << endl;
    cout << "Min - top: " << min.top() << endl;

    // Removing top element
    max.pop();
    min.pop();

    cout << "Max- new top: " << max.top() << endl;
    cout << "Min- new top: " << min.top() << endl;

    // Checking size and empty status
    cout << "Max- size: " << max.size() << ", Empty? " << (max.empty() ? "Yes" : "No") << endl;
    cout << "Min- size: " << min.size() << ", Empty? " << (min.empty() ? "Yes" : "No") << endl;
}

// Linked List is a linear data structure that consists of nodes.
void LinkedList() {
    list<int> myList;

    // Insert elements
    myList.push_back(10); 
    myList.push_front(5);
    myList.push_back(20);
    myList.push_front(2);

    cout << "After insertions: ";
    for (int val : myList) cout << val << " "; 
    cout << endl; 

    // Access front and back
    cout << "Front: " << myList.front() << ", Back: " << myList.back() << endl;         

    // Remove elements
    myList.pop_front();
    myList.pop_back();
    
    cout << "After popping front and back: ";
    for (int val : myList) cout << val << " ";
    cout << endl;

    // Check size and empty status
    cout << "Size: " << myList.size() << endl;
    cout << "Max size: " << myList.max_size() << endl;
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << endl;

    // Iterators
    cout << "Elements using begin-end: ";
    for (auto it = myList.begin(); it != myList.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Elements using rbegin-rend (reverse): ";
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;

    cout << "Elements using cbegin (constant iterator): ";
    for (auto cit = myList.cbegin(); cit != myList.cend(); ++cit)
        cout << *cit << " ";
    cout << endl;
}

int main() {
    Stack();
    cout << "=================="<<endl;
    Queue();
    cout << "=================="<<endl;
    PriorityQueue();
    cout << "=================="<<endl;
    LinkedList();
    return 0;
}
