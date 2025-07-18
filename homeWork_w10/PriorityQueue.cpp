// #include <iostream>
// #include <queue>

// //Using FIFO

// int main() {
    //     priority_queue<int> pq;
    
    //     pq.push(5);
    
    //     pq.push(10);
    //     pq.push(30);
    //     pq.push(20);
    
    //     cout << "Top: " << pq.top() << endl; // 20
    //     pq.pop();
    //     cout << "New Top: " << pq.top() << endl; // 10
    
    //     return 0;
    // }
    
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void minToMax() {
    priority_queue<int, vector<int>, greater<int>> min;

    // Insert elements
    min.push(30);
    min.push(10);
    min.push(50);
    min.push(20);

    cout << "Min- (Smallest First):\n";
    cout << "Size: " << min.size() << endl;

    // Print and remove elements
    while (!min.empty()) {
        cout << "Top: " << min.top() << endl;
        min.pop();
    }
    cout << "Is empty? " << (min.empty() ? "Yes" : "No") << "\n\n";
}

void maxToMin() {
    priority_queue<int> max; // Default (largest element first)

    // Insert elements
    max.push(30);
    max.push(10);
    max.push(50);
    max.push(20);

    cout << "Max- (Largest First):\n";
    cout << "Size: " << max.size() << endl;

    // Print and remove elements
    while (!max.empty()) {
        cout << "Top: " << max.top() << endl;
        max.pop();
    }
    cout << "Is empty? " << (max.empty() ? "Yes" : "No") << "\n\n";
}

int main() {
    minToMax(); // Min-
    maxToMin(); // Max-
    return 0;
}
