// Space O(n)
// Time O(n log n)

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node * pNext;
  int data;

  Node(int _dt = 0): pNext(NULL), data(_dt) {}

  Node * getTail() {
    Node * cur = this;
    while (cur->pNext != NULL) cur = cur->pNext;
    return cur;
  }

  void append(int value) {
    Node * tail = this->getTail();
    tail->pNext = new Node(value);
  }

  void debug() {
    puts("Printing values in linked list");
    for (Node * cur = this; cur != NULL; cur = cur->pNext)
      printf("%d ", cur->data);
    printf("\n");
  }

  int getLength() {
    int numberSteps = 0;
    for (Node * cur = this; cur != NULL; cur = cur->pNext) numberSteps++;
    return numberSteps;
  }
};

void split(Node * head, Node * &a, Node * &b) {
  const int nodeLength = head->getLength();
  const int firstHalfLength = nodeLength / 2;
  
  Node * cur = head;  
  for (int i = 0; i < firstHalfLength-1; ++i) {
    cur = cur->pNext;
  }

  a = head;
  b = cur->pNext;
  cur->pNext = NULL;
}

void appendNode(Node * &node, Node * &a) {
  node->pNext = a;
  node = node->pNext;
  a = a->pNext;
  node->pNext = NULL;
}

void attachHead(Node * &head, Node * &a, Node * &b) {
  if (a == NULL) head = b;
  else if (b == NULL) head = a;
  else {
    if (a->data < b->data) {
      head = a;
      a = a->pNext;
    }
    else {
      head = b;
      b = b->pNext;
    }
    head->pNext = NULL;
  }
}

void sort(Node * &head) {
  if (head == NULL) return;
  if (head->getLength() <= 1) return;

  Node * a, * b;
  split(head, a, b);
  sort(a); sort(b);
  attachHead(head, a, b);
  
  Node * cur = head;
  while (a != NULL || b != NULL) {
    if (a == NULL) appendNode(cur, b);
    else if (b == NULL) appendNode(cur, a);
    else {
      if (a->data < b->data) appendNode(cur, a);
      else appendNode(cur, b);
    }
  }
}

int n;

int main() {
  freopen("input.txt", "r", stdin);
  Node * head = NULL;
  scanf("%d",&n);
  for (int i = 0; i < n; ++i) {
    int dt; scanf("%d",&dt);
    if (head == NULL) head = new Node(dt);
    else head->append(dt);
  }
  head->debug();
  sort(head);
  head->debug();
  return 0;
}