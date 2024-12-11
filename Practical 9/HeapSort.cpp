// Assignment 9 - Heap sort
// AIM: Implementation of Heap sort

#include <iostream>
using namespace std;

class HeapSortList {
private:
    int data[100];
    int size;

    void heapifyMax(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest])
            largest = left;

        if (right < n && data[right] > data[largest])
            largest = right;

        if (largest != i) {
            swap(data[i], data[largest]);
            heapifyMax(n, largest);
        }
    }

    void heapifyMin(int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] < data[smallest])
            smallest = left;

        if (right < n && data[right] < data[smallest])
            smallest = right;

        if (smallest != i) {
            swap(data[i], data[smallest]);
            heapifyMin(n, smallest);
        }
    }

public:
    HeapSortList() {
        size = 0;
    }

    void addValues() {
        cout << "Enter the number of elements (max 100): ";
        cin >> size;

        if (size > 100) {
            cout << "Maximum size is 100. Setting size to 100." << endl;
            size = 100;
        }

        cout << "Enter " << size << " values:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
    }

    void heapSortMax() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyMax(size, i);

        for (int i = size - 1; i > 0; i--) {
            swap(data[0], data[i]);
            heapifyMax(i, 0);
        }
    }

    void heapSortMin() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyMin(size, i);

        for (int i = size - 1; i > 0; i--) {
            swap(data[0], data[i]);
            heapifyMin(i, 0);
        }
    }

    void printList() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HeapSortList heapSortList;

    heapSortList.addValues();

    int choice;
    cout << "Choose sorting method:\n1. Max Heap Sort\n2. Min Heap Sort\nEnter your choice (1 or 2): ";
    cin >> choice;

    cout << "Original list: ";
    heapSortList.printList();

    if (choice == 1) {
        heapSortList.heapSortMax();
        cout << "Sorted list (Max Heap): ";
    } else if (choice == 2) {
        heapSortList.heapSortMin();
        cout << "Sorted list (Min Heap): ";
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    heapSortList.printList();

    return 0;
}

/* OUTPUT:

Enter the number of elements (max 100): 6
Enter 6 values:
12
11
13
5
6
7
Choose sorting method:
1. Max Heap Sort
2. Min Heap Sort
Enter your choice (1 or 2): 1
Original list: 12 11 13 5 6 7 
Sorted list (Max Heap): 13 12 11 7 6 5 
*/
