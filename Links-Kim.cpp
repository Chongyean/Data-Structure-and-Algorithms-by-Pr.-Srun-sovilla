#include <iostream>
using namespace std;


// Link Class (Node Structure)
//Single Node in the linked list
class Link {
public:
    int data; // Store data
    Link* next; // Pointer to the next link
    void initLink(int value) {
        data = value;
        next = NULL;
    }
};

// ================================================================================

class LinkedList {
private:
    Link* head; // Pointer to the first node of the link
public:
    void initList();
    void insertAtPosition(int value, int position);
    void deleteAtPosition(int position);
    void displayList();
    void insertAtTail(int value);
};

// ================================================================================
// Initialize list
void LinkedList::initList() {
    head = NULL; // Set head to NULL so that the list is empty
}

// ================================================================================
// Insert at a specific position
void LinkedList::insertAtPosition(int value, int position) {
    Link* newLink = new Link();  //Create new link
    newLink->initLink(value);    //Initialize it with value

    if (position == 1) {    //If position 1 then set the new link as head
        newLink->next = head;
        head = newLink;
        return;
    }

    Link* temp = head;
    while (temp->next && --position > 1) { //Find the position where the link should insert
        temp = temp->next;
    }

    if (temp->next == nullptr && position > 1) return; // Invalid position

    newLink->next = temp->next;  //new link next pointer is set to the same pointer as temp link  
    temp->next = newLink; //temp point the the new link
}

// ================================================================================
// Delete at a specific position
void LinkedList::deleteAtPosition(int position) {
    if (head == NULL) return; // List is empty

    Link* temp = head;

    // If deleting the first node (head)
    if (position == 1) { 
        head = head->next; // Move head to the next node
        delete temp; // Delete the old head
        return;
    }

    // Find the node before the one we want to delete
    Link* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If position is invalid or out of range, exit
    if (temp == NULL) return; 

    prev->next = temp->next; // Change pointer to skip temp (deleted node)
    delete temp; // Now we can safely delete the node
}

// ================================================================================
// Display linked list
void LinkedList::displayList() {
    Link* temp = head;

    while (temp) {
        cout << "Value: " << temp->data << " | Address: ";
        if (temp->next == NULL)
            cout << "0" << endl;
        else
            cout << temp->next << endl;
        temp = temp->next;
    }
}

// ================================================================================
// Insert at the tail
void LinkedList::insertAtTail(int value) {
    Link* newNode = new Link();
    newNode->initLink(value);
    
    if (head == NULL) {     // If list is empty, set head
        head = newNode;
        return;
    }

    Link* temp = head;
    while (temp->next) {    // Traverse to last node
        temp = temp->next;
    }

    temp->next = newNode;   // Link new node to the last node
}

// ================================================================================
int main() {
    LinkedList myList;
    myList.initList();
    
    // Creating 10 connected nodes
    for (int i = 5; i <= 50; i+=5) {
        myList.insertAtTail(i);
    }
    
    myList.displayList();
    cout << endl;

    myList.insertAtPosition(99, 3);
    myList.displayList();
    cout << endl;

    myList.deleteAtPosition(5); // Example deletion
    myList.displayList();
    cout << endl;
    
    myList.insertAtTail(25);
    myList.displayList();
    return 0;
}
