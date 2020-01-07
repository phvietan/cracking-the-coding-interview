// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. Ifxis contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions

// This code initialize 2 new linkedlist then iterate the original linkedlist from left to right, if find value < x append it to the first new linkedlist, else append to the other linkedlist.
// Finally, concat the 2 new linkedlist.
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node * pNext;
  int data;

  Node(int _dt = 0): data(_dt), pNext(NULL) {}

  void debug() {
    puts("Printing the linkedlist");
    for (Node * cur = this; cur != NULL; cur = cur->pNext)
      printf("%d ", cur->data);
    puts("");
  }

  Node * getTail() {
    Node * cur = this;
    for (; cur->pNext != NULL; cur = cur->pNext);
    return cur;
  }

  void append(int data) {
    Node * tail = this->getTail();
    tail->pNext = new Node(data);
  }
};

struct LinkedListManager {
  Node * head;

  LinkedListManager(): head(NULL) {}

  Node * getHead() { return this->head; }

  void append(int data) {
    if (this->head == NULL) this->head = new Node(data);
    else this->head->append(data);
  }
};

LinkedListManager merge(LinkedListManager & A, LinkedListManager & B) {
  A.getHead()->getTail()->pNext = B.getHead();

  LinkedListManager result;
  result.head = A.getHead();
  return result;
}

void partition(LinkedListManager & A, int x) {
  LinkedListManager B, C;

  for (Node * cur = A.getHead(); cur != NULL; cur = cur->pNext) {
    if (cur->data < x) B.append(cur->data);
    else C.append(cur->data);
  }

  A = merge(B, C);
}

int main() {
  freopen("input.txt", "r", stdin);
  int n, x;
  scanf("%d %d",&n, &x);
  
  LinkedListManager A;

  for (int i = 0; i < n; ++i) {
    int x; scanf("%d",&x);
    A.append(x);
  }
  A.getHead()->debug();
  partition(A, x);
  A.getHead()->debug();
  return 0;
}