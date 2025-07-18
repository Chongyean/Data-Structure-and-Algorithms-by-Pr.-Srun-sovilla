#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int listSize;

public:
    LinkedList() {
        head = nullptr;
        listSize = 0;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        listSize++;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        listSize++;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        listSize--;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        listSize--;
    }

    int size() {
        return listSize;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);

    cout << "List size: " << list.size() << endl;
    list.pop_front();
    cout << "List size after pop: " << list.size() << endl;

    return 0;
}
