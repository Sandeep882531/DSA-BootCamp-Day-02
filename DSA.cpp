#include <iostream>
#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    void enqueue(int value) {
        if (count == MAX) {
            std::cout << "Queue is full. Cannot enqueue " << value << "." << std::endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
        std::cout << "Enqueued: " << value << std::endl;
    }

    int dequeue() {
        if (count == 0) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % MAX;
        count--;
        std::cout << "Dequeued: " << value << std::endl;
        return value;
    }

    void display() {
        if (count == 0) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue contents: ";
        for (int i = 0; i < count; i++) {
            std::cout << arr[(front + i) % MAX] << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == MAX;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    q.dequeue();

    return 0;
}
