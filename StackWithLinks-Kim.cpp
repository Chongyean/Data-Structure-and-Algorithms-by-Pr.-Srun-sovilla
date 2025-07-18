#include <iostream>
using namespace std;

class Link {
public:
    int data;
    Link* next;
    void initLink(int data) {
        data = data;
        next = NULL;
    }
};

// ================================================================================
class LinkedList {
private:
    Link* head;
public:
    void initList();
    void insertFirst(int data);  //Push
    void printFirst();
    void deleteAllLink();
    void deleteFirst();     //Pop
    void peek();//no remove or delete but display elements in the top of the list
    void size(); //count how many link/element in the list
};

// ================================================================================
// Initialize list
void LinkedList::initList() {
    head = NULL;
}

// ================================================================================
void LinkedList::insertFirst(int data) {
    Link* newLink = new Link();
    newLink->initLink(data);

    newLink->next = head;
    head = newLink;

    //cout << "Inserted: " << head->data << " at " << head << ", Next: " << head->next << endl;
}

// ================================================================================
void LinkedList::deleteFirst() {
    Link* temp = head;
    head = head->next;
    delete temp;
}

// ================================================================================
void LinkedList::peek() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        cout << "First element is: " << head->data << endl;
    }
}

// ================================================================================
void LinkedList::size() {
    int count = 0;
    Link* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        cout << "Size of Linked List: " << count << endl;
    }
}

// ================================================================================
void LinkedList::printFirst() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        //cout << head->data << " " << head << endl;

        Link* temp = head;

            cout << head->data << " address: ";

            if (temp->next == NULL)
                cout << "0" << endl;
            else
                cout << temp->next << endl;
            temp = temp->next;

    }
}

// ================================================================================
void LinkedList::deleteAllLink() {
    while (head != NULL) {
        deleteFirst();
    }
}
// ================================================================================
int main() {
    LinkedList myList;

    myList.initList();
    myList.insertFirst(5);
    myList.insertFirst(10);
    myList.insertFirst(20);
    // myList.insertFirst(30);

    myList.printFirst();
    myList.peek();
    myList.size();
    cout << endl;

    myList.deleteFirst();
    cout << endl;
    myList.printFirst();
    myList.peek();
    myList.size();

    // myList.deleteFirst();
    // cout << endl;
    // myList.printFirst();
    // myList.peek();
    // myList.size();

    cout << endl;
    myList.deleteAllLink();
    myList.printFirst();
    
    return 0;
}
