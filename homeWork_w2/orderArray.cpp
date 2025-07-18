//Order Array (Binary Search, Insert, and Deletion)

#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;


// Function to display the elements of the ordered array
void displayArray(const vector<int>& arr) {
    cout << "Ordered Array : ";
    for (int val : arr){
        cout << val << " ";
    }
    cout << endl;
}

// Function to insert multiple elements while maintaining order
void insertElements(vector<int>& arr) {
    int n, value;
    cout << "Enter the number of elements : ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        arr.push_back(value); // Add each value
    }
    sort(arr.begin(), arr.end()); // Sort to maintain the order
    cout << n << " elements inserted successfully.\n";
}

// Function to delete an element by value
void deleteElement(vector<int>& arr, int value){
    auto it = find(arr.begin(), arr.end(), value); // Find the element
    if (it != arr.end()){
        arr.erase(it); // Delete the element if found
        cout << "Element " << value << " deleted successfully.\n";
    } else {
        cout << "Element not found in the array.\n";
    }
}

// Function to perform binary search on the ordered array
void binarySearch(const vector<int>& arr, int value) {
    int lower = 0, upper = arr.size() - 1, mid;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            if (arr[mid] == value) {
                cout << "Element " << value << " found at index " << mid << ".\n";
                return;
            } else if (arr[mid] < value) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
    cout << "Element " << value << " not found in the array.\n";
}

void ui(){

    vector<int> orderedArray; // Ordered array
    int choice, value;

    while (true) {

        cout << "\n----------------------------------------------------------------\n";
        cout << "Homework 3 - Ordered Array (Binary Search, Insert, and Deletion)\n";
        cout << "\n--- Ordered Array Operations ---\n";
        cout << "1. Display Array\n2. Insert Element\n3. Delete Element\n4. Binary Search\n5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1:
            displayArray(orderedArray);
            break;
        case 2:
            cout << "Enter number for order : ";
            cin >> value;
            insertElements(orderedArray);
            break;
        case 3:
            cout << "Enter element to delete: ";
            cin >> value;
            deleteElement(orderedArray, value);
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> value;
            binarySearch(orderedArray, value);
            break;
        case 5:
            cout << "Exiting program.\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    ui();
    return 0;
}
