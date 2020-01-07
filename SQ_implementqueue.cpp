// My implementation for queue

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node * pNext;
  int data;

  Node(int _data = 0): data(_data), pNext(NULL) {}
};

struct Queue {
  Node * front, * rear;

  Queue(): front(NULL), rear(NULL) {}

  bool isEmpty() {
    return front == NULL || rear == NULL;
  }

  void push(int data) {
    if (this->isEmpty()) {
      front = new Node(data);
      rear = front;
    } else {
      rear->pNext = new Node(data);
      rear = rear->pNext;
    }
  }

  int get() {
    if (this->isEmpty()) throw "Queue.get error: Queue is empty";
    return this->front->data;
  }

  void pop() {
    if (this->isEmpty()) throw "Queue.pop error: Queue is empty";
    front = front->pNext;
    if (front == NULL) rear = NULL;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  Queue Q;
  int n; scanf("%d",&n);
  for (int i = 0; i < n; ++i) {
    int data; scanf("%d",&data);
    Q.push(data);
  }
  cout << Q.get() << endl;
  Q.pop();
  Q.pop();
  cout << Q.get() << endl;
  Q.push(123456);
  Q.pop(); Q.pop(); Q.pop();
  cout << Q.get() << endl;
  return 0;
}