#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Ascending or Descending order logic
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 20, 15, 79};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array : ";
    printArray(arr, n);

    // Sort in ascending order
    bubbleSort(arr, n, true);
    cout << "Sorted array in ascending order : "; // Small to large
    printArray(arr, n);

    // Sort in descending order
    bubbleSort(arr, n, false);
    cout << "Sorted array in descending order : "; // Large to small
    printArray(arr, n);

    return 0;
}
