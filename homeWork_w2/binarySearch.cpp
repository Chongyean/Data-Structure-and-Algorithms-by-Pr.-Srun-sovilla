#include <iostream>
using namespace std;

// Function for binary search
int binarySearch(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Calculate mid index
        int mid = low + (high - low) / 2;

        // Check if the target is found
        if (arr[mid] == target) {
            return mid; // Target found, return the index
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    // Example array (must be sorted)
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Target to search
    int target;
    cout << "Enter the target number: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output the result
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << ".\n";
    } else {
        cout << "Target " << target << " not found in the array.\n";
    }

    return 0;
}
