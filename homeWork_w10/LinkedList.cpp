#include <iostream>
#include <list>

using namespace std;

void linkedListQueueOperations() {
    list<int> myList;

    // Insert elements using push_front() and push_back()
    myList.push_front(5);
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(2);

    cout << "After insertions: ";
    for (int val : myList) cout << val << " ";
    cout << endl;

    // Access front and back elements
    cout << "Front: " << myList.front() << ", Back: " << myList.back() << endl;

    // Remove elements using pop_front() and pop_back()
    myList.pop_front();  // Removes 2
    myList.pop_back();   // Removes 20

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
    linkedListQueueOperations();
    return 0;
}
