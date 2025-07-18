#include <iostream>
using namespace std;

// Predefined array
int number[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int x = 10; // Number of elements in the array (fixed)

// Function to display the elements of the array
void displayArray() {
    cout << "Ordered Array: ";
    for (int i = 0; i < x; ++i) {
        cout << number[i] << " ";
    }
    cout << endl;
}

// Function to delete an element by value
void deleteElement(int value) {
    int index = -1;
    for (int i = 0; i < x; ++i) {
        if (number[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element " << value << " not found in the array.\n";
        return;
    }

    // Shift elements to the left to remove the value
    for (int i = index; i < x - 1; ++i) {
        number[i] = number[i + 1];
    }
    x--; // Reduce the size of the array
    cout << "Element " << value << " deleted successfully.\n";
}

// Function to perform binary search on the array
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Ordered Array Operations ---\n";
        cout << "1. Display Array\n2. Delete Element\n3. Binary Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1:
            displayArray();
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> value;
            deleteElement(value);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> value;
            binarySearch(number, 0, x - 1, value) == -1
                ? cout << "-----xxxx Element not found. xxxx-----\n"
                : cout << "====== Element found ======" << endl;
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
