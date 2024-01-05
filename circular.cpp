#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (front == NULL) {
            front = newNode;
        } else {
            rear->next = newNode;
        }

        rear = newNode;
        rear->next = front; // Make the queue circular

        cout << "Enqueued: " << data << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty. Dequeue operation cannot be performed." << endl;
            return;
        }

        int removedData = front->data;
        Node* temp = front;

        if (front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            delete temp;
            rear->next = front; // Update rear to maintain the circular structure
        }

        cout << "Dequeued: " << removedData << endl;
    }

    void displayForward() {
        cout << "Queue (Forward): ";
        if (front == NULL) {
            cout << "Empty" << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);

        cout << endl;
    }

    void displayReverse() {
        cout << "Queue (Reverse): ";
        if (front == NULL) {
            cout << "Empty" << endl;
            return;
        }

        Node* current = rear;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear);

        cout << endl;
    }
};

int main() {
    CircularQueue circularQueue;

    // Enqueue elements
    circularQueue.enqueue(1);
    circularQueue.enqueue(2);
    circularQueue.enqueue(3);

    // Display forward and reverse
    circularQueue.displayForward();
    circularQueue.displayReverse();

    // Dequeue elements
    circularQueue.dequeue();
    circularQueue.dequeue();

    // Display forward and reverse after dequeuing
    circularQueue.displayForward();
    circularQueue.displayReverse();

    return 0;
}
