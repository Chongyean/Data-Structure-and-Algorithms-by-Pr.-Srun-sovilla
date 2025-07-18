#include <iostream>
//LIFO
using namespace std;

int arr[ 10 ];
int top = -1;

//Push value to stack function
//Push = to insert item on the top of stack.
void push(int value){
	if(top == 9){
		cout << "Stack Full" << endl;
	}
	else {
		cout << " \t " << value << " pushed into stack" << endl;
		top++;
		arr[top] = value;
	}
}

//Pop value from stack function
//Pop = to remove data item from the top of stack.
void pop(){
	if(top == -1){
		cout << "Stack Not Full" << endl;
	}
	else {
		top--;
	}
}

//Peek value from stack function
//Peek = to showArrayprint value from the top of the stack without removing it.
void peek(){
	if(top == -1){
		cout << "Stack is Empty" << endl;
	}else{
		cout << arr[top] << endl;
	}
}

//Check if stack is empty function
//isEmpty = to check if the stack is empty.
void isEmpty(){
	if(top == -1){
		cout << "Stack is Empty" << endl;
	}else{
		cout << "Stack is not Empty" << endl;
	}
}

//Size of stack function
//Size = to return the number of data items in the stack.
void size(){
	cout << "Size : " << top + 1 << endl;
}

//isFull function
//isFull = to check if the stack is full.
void isFull(){
	if(top == 9){
		cout << "Stack is Full" << endl;
	}else{
		cout << "Stack is not Full" << endl;
	}
}

//Function to Output the Array
void showArray()
{
	int i;
	for (i = 0; i <= top ; ++i)
		cout << " " << arr[i] ;
	cout << endl;
};

int main(){

	//Play Ground with the 6 functions in the stack;

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);

	//Expect output stackoverflow
	cout << "\n\t";
	push(110);

	size();

	cout << "\t=======================\n\t";
	showArray();
	cout << "\t=======================\n\t";
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();

	//output stackunderflow
	pop();

	//output 10
	peek();

	//output stack is not empty
	isEmpty();

	//output stack is not full
	size();

	//output stack is empty
	isFull();

	return 0;
}


/*
Push = to insert data item on the top of stack.

Pop = to remove data item from the top of stack.

Peek = to read value from the top of the stack without removing it.

Size = to return the number of data items in the stack.

isEmpty = to check if the stack is empty.

isFull = to check if the stack is full.
*/