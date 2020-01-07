// Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks
// Maintain 1 stack as the left, 1 stack as the right
// When pop, the left would pop its top
// When push, the right would push to its top
// If the left stack is empty and cannot pop when in pop operation, swap the 2 stacks
// Push time: O(1)
// Pop time: O(n) because swaping the stack
// GEt time: O(n) because swaping the stack
// Storage: O(n).

#include <bits/stdc++.h>

using namespace std;


struct Node {
  Node * pNext;
  int data;

  Node(int data = 0) {
    this->data = data;
    this->pNext = NULL;
  }
};

struct Stack {
  Node * top;

  Stack(): top(NULL) {}

  bool isEmpty() { return this->top == NULL; }

  void push(int data) {
    if (top == NULL) top = new Node(data);
    else {
      Node * newHead = new Node(data);
      newHead->pNext = top;
      top = newHead;
    }
  }

  int seek() {
    if (top == NULL) throw "Stack.seek error: Stack is empty";
    return top->data;
  }

  void pop() {
    if (top == NULL) throw "Stack.pop error: Stack is empty";
    Node * popTop = top->pNext;
    delete top;
    top = popTop;
  }
};

struct Queue {
  Stack left, right;

  Queue() {}

  bool isEmpty() { return left.isEmpty() && right.isEmpty(); }

  void push(int data) {
    right.push(data);
  }

  void swapStack() {
    while (!right.isEmpty()) {
      left.push(right.seek());
      right.pop();
    }
  }

  void pop() {
    if (this->isEmpty()) throw "Queue.pop error: Queue is empty";
    if (left.isEmpty()) this->swapStack();
    left.pop();
  }

  int get() {
    if (this->isEmpty()) throw "Queue.get error: Queue is empty";
    if (left.isEmpty()) this->swapStack();
    return left.seek();
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  Queue Q;
  int n; scanf("%d",&n);
  for (int i = 0; i < n; ++i) {
    int value; scanf("%d",&value);
    Q.push(value);
  }

  cout << Q.get() << endl;
  Q.pop();
  cout << Q.get() << endl;
  Q.pop();
  cout << Q.get() << endl;
  Q.pop();
  cout << Q.get() << endl;
  Q.pop();
  cout << Q.get() << endl;
  Q.pop();

  Q.push(123456); Q.push(789);
  cout << Q.get() << endl;
  Q.pop();
  cout << Q.get() << endl;

  return 0;
}