#include <iostream>
using namespace std;


int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value;

    cout << "Enter the value to search: ";
    cin >> value;

    searchElementInArray(arr, size, value);

    return 0;
}

void searchElementInArray( int arr[], int size, int value ) {
    int count = 0; //count occurrences of the value

    // Traverse the array to count occurrences
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }

    // Output based on the count
    if (count == 0) {
        cout << "The value " << value << " is not found in the array." << endl;
    } else if (count == 1) {
        cout << "The value " << value << " is found once in the array (non-duplicate)." << endl;
    } else {
        cout << "The value " << value << " is found " << count << " times in the array (duplicate)." << endl;
    }

}
