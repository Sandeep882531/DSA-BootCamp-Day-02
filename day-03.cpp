#include <iostream>

class CircularQueue {
private:
    int* queue;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % capacity;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        int i = front;
        do {
            std::cout << queue[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display(); // Displays: 10 20 30 40 50

    cq.dequeue();
    cq.display(); // Displays: 20 30 40 50

    cq.enqueue(60);
    cq.display(); // Displays: 20 30 40 50 60

    return 0;
}
