// Palindrome: Implement a function to check if a linked list is a palindrome.
// This method takes O(n) time and O(1) extra space.
// 1) Get the middle of the linked list.
// 2) Reverse the second half of the linked list.
// 3) Check if the first half and second half are identical.

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node * pNext;
  char data;

  Node(char _data = 0): data(_data), pNext(NULL) {}

  Node * getTail() {
    Node * cur = this;
    while (cur->pNext != NULL) cur = cur->pNext;
    return cur;
  }

  void append(char data) {
    Node * tail = this->getTail();
    tail->pNext = new Node(data);
  }

  int getNumberOfNodes() {
    int numberOfNodes = 0;
    for (Node * cur = this; cur != NULL; cur = cur->pNext)
      numberOfNodes += 1;
    return numberOfNodes;
  }

  void debug() {
    puts("Printing linkedlist");
    for (Node * cur = this; cur != NULL; cur = cur->pNext)
      printf("%c", cur->data);
    puts("");
    puts("================");
  }
};

Node * getSecondHalf(Node * head, const int n) {
  const int steps = (n+1) / 2;
  Node * res = head;
  for (int i = 0; i < steps; ++i) res = res->pNext;
  return res;
}

void detach(Node * firstHalf, Node * secondHalf) {
  Node * it = firstHalf;
  while (it->pNext != secondHalf) it = it->pNext;
  it->pNext = NULL;
}

void reverseLinkedList(Node * &head) {
  if (head == NULL) return;

  Node * cur = head;
  Node * nCur = cur->pNext;
  cur->pNext = NULL;
  while (nCur != NULL) {
    Node * nnCur = nCur->pNext;
    nCur->pNext = cur;
    cur = nCur;
    nCur = nnCur;
  }

  head = cur;
}

bool isPalindrome(Node * head) {
  if (head == NULL) return true;
  const int n = head->getNumberOfNodes();
  if (n == 1) return true;

  // Get first half and second half then reverse second half
  Node * firstHalf = head;
  Node * secondHalf = getSecondHalf(head, n);
  detach(firstHalf, secondHalf);
  reverseLinkedList(secondHalf);

  // Check palindrome
  while (firstHalf != NULL && secondHalf != NULL) {
    if (firstHalf->data != secondHalf->data) return false;
    firstHalf = firstHalf->pNext;
    secondHalf = secondHalf->pNext;
  }
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n; scanf("%d",&n);

  Node * head = NULL;
  string s; getline(cin, s);
  for (int i = 0; i < s.length(); ++i) {
    if (i == 0) head = new Node(s[0]);
    else head->append(s[i]);
  }

  cout << (isPalindrome(head) ? "YES" : "NO") << endl;
  return 0;
}