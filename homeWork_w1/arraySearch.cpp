#include <iostream>
using namespace std;

void searchValue(int arr[], int size, int value) {
    int count = 0;

    // Count occurrences of the value in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }

    // Check count and print result
    if (count == 0) {
        cout << "Value not found in the array." << endl;
    } else if (count == 1) {
        cout << "Value is a non-duplicate element." << endl;
    } else {
        cout << "Value is a duplicate element." << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 5, 3, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value;

    cout << "Enter the value to search : ";
    cin >> value;

    searchValue(arr, size, value);

    return 0;
}
