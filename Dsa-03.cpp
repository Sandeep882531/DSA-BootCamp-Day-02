#include <iostream>

class Deque {
private:
    int* deque;
    int front, rear, capacity;

public:
    Deque(int size) {
        capacity = size;
        deque = new int[capacity];
        front = rear = -1;
    }

    ~Deque() {
        delete[] deque;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int value) {
        if (isFull()) {
            std::cout << "Deque is full!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        deque[front] = value;
    }

    void insertRear(int value) {
        if (isFull()) {
            std::cout << "Deque is full!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty!" << std::endl;
            return -1;
        }
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty!" << std::endl;
            return -1;
        }
        return deque[rear];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        int i = front;
        do {
            std::cout << deque[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        std::cout << std::endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(30);
    dq.insertFront(40);
    dq.display(); // Displays: 40 30 10 20

    dq.deleteFront();
    dq.display(); // Displays: 30 10 20

    dq.deleteRear();
    dq.display(); // Displays: 30 10

    dq.insertRear(50);
    dq.insertFront(60);
    dq.display(); // Displays: 60 30 10 50

    return 0;
}
