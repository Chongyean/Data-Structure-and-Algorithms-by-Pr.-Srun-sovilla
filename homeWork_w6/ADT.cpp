// ADT is a Data type that is defined by the operations rather than it implemention.

#include<iostream>

using namespace std;
class Stack{
    private:
        int Number[10]; 
        int top = -1;
    public:
        void push(int value); //push element to top
        void pop();
        void peek();
        void size();
        bool isEmpty();
        bool isFull();
        void display();
};

void Stack::push(int value){
    if (top < 9) {
        top++;
        Number[top] = value;
    } else {
        cout << "Array is full" << endl;
    }
}
void Stack::pop(){
    if (top >= 0)
    { top--; }
    else cout << "Array is empty" << endl;
}
void Stack::peek() { cout << "The Last Number is " << Number[top] << endl; }

void Stack::size() { cout << "Array Size: " << top + 1 << endl; }

bool Stack::isEmpty() { return top < 0; }

bool Stack::isFull() { return top >= 9; }

void Stack::display(){
    cout << "[ ";
    for (int i = 0; i <= top; i++) { cout << Number[i] << " "; }
    cout << " ]" << endl;
}

int main(){
    Stack stack;
    stack.push(10);
    stack.push(100);
    stack.push(90);

    //Checking
    stack.size();
    stack.peek();
    stack.display();
    stack.pop();

    // Show the Output
    stack.display();
    cout << stack.isEmpty() << endl;
    cout << stack.isFull() << endl;

    return 0;
}
