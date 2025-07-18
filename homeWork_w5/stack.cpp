#include <iostream>
using namespace std;

int number [10]; 
int top = -1; // default value for top

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << number[i] << " ";
        }
        cout << endl;
    }
}

// Adds a value to the stack 
void push(int value)
{
    if (top == 9)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        number[top] = value; 
    }
    display();
}

// Removes the top element from the stack
void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "The value " << number[top] << " is popped" << endl;
        top--;
    }
    display();
}

// Displays the top value of the stack
void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "The value at the top is " << number[top] << endl;
    }
}

// Checks if the stack is full
void isFull()
{
    if (top == 9)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }
}

// Checks if the stack is empty
void isEmpty()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

// Returns the size of the stack
void size()
{
    cout << "Size of the stack is " << top + 1 << endl;

}


int main() 
{
    system("cls");
    int choice, value;
    while (true)
    {
        cout << "=================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Is Full" << endl;
        cout << "5. Is Empty" << endl;
        cout << "6. Size" << endl;
        cout << "0. Exit" << endl;
        cout << "=================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isFull();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                size();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
