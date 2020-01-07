// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other
// If a is permutation of b, then a and b have same length; and the number of occurence of every character in a is equal to b

// If a and b are utf8 characters, then we should sort a and b then check a equal to b. Because utf8 supports over 1 million characters.
// Time: O(n log n)
// Space: O(n)

// But if a and b are very long, longer than 1m, then we create another array to store the number of occurence of each character in a and b and compare
// This code use sort and compare

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char buf1[N], buf2[N];

bool checkPermutation(char * a, char * b) {
  if (strlen(a) != strlen(b)) return false;
  
  sort(a, a+strlen(a));
  sort(b, b+strlen(b));
   
  return strncmp(a, b, strlen(a)) == 0;
}

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%s\n", buf1);
  scanf("%s\n", buf2);

  if (checkPermutation(buf1, buf2)) puts("YES");
  else puts("NO");
  return 0;
}