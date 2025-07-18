#include <iostream>
#include <stack>

using namespace std;

void stackOperations() {
    stack<int> myStack;

    // push elements into the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    // Pop elements and display top
    while (!myStack.empty()) {
        cout << "Popping: " << myStack.top() << endl;
        myStack.pop();
    }

    // Check if stack is empty
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;
}

int main() {
    stackOperations();
    return 0;
}
