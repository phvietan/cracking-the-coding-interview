// Remove Dups: Write code to remove duplicates from an unsorted linked list. FOLLOW UP How would you solve this problem if a temporary buffer is not allowed

// This code use Set data structure of c++, which results in O(n log n) to remove dups, space O(n) of redblack tree set.
// We can also iterate n^2 if we dont use any data structure, space O(n) because no new buffer or data structure
// We can also sort the linkedlist using mergesort, then remove adjacent nodes with same data O(n log n) but this approach does not maintain the order of linkedlist, space O(n) because mergesort

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node * pNext;

  Node(int _dt = 0): data(_dt), pNext(NULL) {}
  
  Node * getTail() {
    Node * tail = this;
    while (tail->pNext != NULL) tail = tail->pNext;
    return tail;
  }

  void append(int dt) {
    Node * tail = this->getTail();
    tail->pNext = new Node(dt);
  }

  void debug() {
    puts("Printing linkedlist values");
    for (Node * cur = this; cur != NULL; cur = cur->pNext)
      printf("%d ", cur->data);
    printf("\n");
  }
};

set <int> S;

void removedups(Node * head) {
  if (head == NULL) return;

  S.insert(head->data);
  Node * newLinkedList = head;
  
  // Start from head+1
  for (Node * cur = head->pNext; cur != NULL; cur = cur->pNext) {
    if (S.find(cur->data) == S.end()) {
      newLinkedList->pNext = cur;
      newLinkedList = newLinkedList->pNext;
      S.insert(cur->data);
    }
  }
  newLinkedList->pNext = NULL;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n; scanf("%d",&n);
  Node * head = NULL;
  for (int i = 0; i < n; ++i) {
    int dt; scanf("%d",&dt);
    if (head == NULL) head = new Node(dt);
    else head->append(dt);
  }

  head->debug();
  removedups(head);
  head->debug();
  return 0;
}