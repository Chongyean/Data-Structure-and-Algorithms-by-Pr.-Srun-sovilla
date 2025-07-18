#include <iostream>
using namespace std;

class Link {
public:
    int data;
    Link* next;

    // Constructor for the Link node
    Link(int data) {
        this->data = data; 
        this->next = NULL;
    }

    void insert(int data);
    void insertAt(int data, int position);
    void remove(int position);
    void insertTail(int data);
    void print();
};

// Insert at the end of the list
void Link::insert(int data) {
    Link* newNode = new Link(data); // Create new node
    Link* temp = this;  // Start from the current node
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Add new node at the end
}

// Insert at a specific position
void Link::insertAt(int data, int position) {
    Link* newNode = new Link(data);
    Link* temp = this; // Start from the current node
    if (position == 0) {
        newNode->next = temp->next;
        temp->next = newNode; 
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next; // Insert the node
    temp->next = newNode; // Add new node at the end
}

// Remove a node at a specific position
void Link::remove(int position) {
    if (this->next == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Link* temp = this;
    if (position == 0) {
        Link* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        return;
    }
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    Link* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Insert at the tail
void Link::insertTail(int data) {
    Link* newNode = new Link(data);
    Link* temp = this;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the linked list
void Link::print() {
    Link* temp = this->next; // Start from the first node (skip the dummy node)
    while (temp != NULL) {
        cout << "Value: " << temp->data << ", Address: " << temp << ", Next: " << temp->next << endl;
        temp = temp->next;
    }
}

// Main function to test the linked list
int main() {
    Link myList(0);  // Initial dummy node to act as head

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);
    myList.insert(6);
    myList.insert(7);
    myList.insert(8);
    myList.insert(9);
    myList.insert(10);

    cout << "Initial List:" << endl;
    myList.print();

    myList.insertAt(25, 5);
    cout << "\nList after inserting 25 at position 5:" << endl;
    myList.print();

    myList.remove(3);
    cout << "\nList after deleting node at position 3:" << endl;
    myList.print();

    myList.insertTail(100);
    cout << "\nList after inserting 100 at the tail:" << endl;
    myList.print();

    return 0;
}