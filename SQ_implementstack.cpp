// My implementation for stack

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

int main() {
  freopen("input.txt", "r", stdin);
  int n; scanf("%d",&n);
  Stack S;
  for (int i = 0; i < n; ++i) {
    int data; scanf("%d",&data);
    S.push(data);
  }
  cout << S.seek() << endl;
  S.pop();
  cout << S.seek() << endl;
  S.push(12);
  cout << S.seek() << endl;
  S.pop(); S.pop(); S.pop();
  cout << S.seek() << endl;
  return 0;
}