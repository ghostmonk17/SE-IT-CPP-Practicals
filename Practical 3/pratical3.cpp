//Question
/*
Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)
*/

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* queue;
    int maxSize;

public:
    CircularQueue(int size) {
        this->maxSize = size;
        this->front = -1;
        this->rear = -1;
        this->size = 0;
        queue = new int[maxSize];
    }


    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == maxSize;
    }

    bool isEmpty() {
        return size == 0;
    }

    //Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; 
        } else {
            rear = (rear + 1) % maxSize; 
        }
        queue[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front = (front + 1) % maxSize; 
        size--;
    }

 
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue cq(size);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


//Output
/*
Enter the size of the queue: 3

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 2
Enqueued: 2

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 3
Enqueued: 3

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 2 3 

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued: 2

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 3 

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting...


=== Code Execution Successful ===
*/
