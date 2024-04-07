#include <iostream>

#define MAX_SIZE 100 

using namespace std;

class Queue {
private:
  int data[MAX_SIZE]; 
  int front, rear;     

public:
  Queue() {
    front = rear = -1; 
  }

  bool isEmpty() const {
    return front == -1; 
  }

  bool isFull() const {
    return rear == MAX_SIZE - 1; 
  }

  void enqueue(int value) {
    if (isFull()) {
      cout << "Antrian penuh!" << endl;
      return;
    }

    data[++rear] = value; 
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Antrian kosong!" << endl;
      return -1; 
    }

    int temp = data[front++]; 

    if (front > rear) { 
      front = rear = -1;
    }

    return temp;
  }

  int peek() const {
    if (isEmpty()) {
      cout << "Antrian kosong!" << endl;
      return -1; 
    }

    return data[front]; 
  }
};

int main() {
  Queue antrian;

  antrian.enqueue(10);
  antrian.enqueue(20);
  antrian.enqueue(30);

  cout << "Elemen yang dikeluarkan: " << antrian.dequeue() << endl;
  cout << "Elemen depan: " << antrian.peek() << endl;

  return 0;
}
