#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* frt = NULL;

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = frt;
    frt = newNode;
}

void dequeue() {
    if (frt == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* temp = frt;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    delete frt;
    frt = temp;
    frt->next = NULL;
}

int peek() {
    if (frt == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    Node* temp = frt;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

void clear() {
    while (frt != NULL) {
        Node* temp = frt;
        frt = frt->next;
        delete temp;
    }
}

int size() {
    int count = 0;
    Node* temp = frt;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
const int MAX_SIZE = 5;
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue1(int value) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << value << " enqueued to queue" << endl;
}

void dequeue1() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << queue[front] << " dequeued from queue" << endl;
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void peek1() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element is: " << queue[front] << endl;
}

void clear1() {
    front = rear = -1;
    cout << "Queue is cleared!" << endl;
}

int getSize() {
    if (front == -1) {
        return 0;
    }
    return rear - front + 1;
}

int main() {


    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Front element: " << peek() << endl;
    cout << "Queue size: " << size() << endl;
    dequeue();
    cout << "Front element after dequeue: " << peek() << endl;
    cout << "Queue size after dequeue: " << size() << endl;
    clear();
    cout << "Queue size after clear: " << size() << endl;


    enqueue1(10);
    enqueue1(20);
    enqueue1(30);
    peek1();
     cout << "Size of queue is: " << getSize() << endl;
    dequeue1();
     cout << "Size of queue is: " << getSize() << endl;
    peek();
    clear1();
    cout << "Size of queue is: " << getSize() << endl;
    return 0;
}
