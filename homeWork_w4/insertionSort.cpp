#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, tmp, j;
	for (i = 1; i < n; i++) {
		tmp = arr[i]; // Remove marked items
		j = i - 1; // start shifts at ith

		while (j >= 0 && arr[j] > tmp) { // Until the one is smaller
			arr[j + 1] = arr[j]; //otherwise, shift item to right
			j = j - 1; // go left one position
		}
		arr[j + 1] = tmp; //insert marked item
	}
}

// A utility function to print
// an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 65, 32, 18, 80, 74, 21, 50 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}

