// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
// I saw many tutorials online and for god sake, the problem did not state that input is ascii character, so we should not have any assumption about the number of different characters in the string, maybe thousands due to utf8?
// Just sort and compare
// Time: O(n log n)
// Space: O(n)

#include <bits/stdc++.h>

using namespace std;

char buf[100005];

bool isUnique(char buf[]) {
  int n = strlen(buf);
  sort(buf, buf+n);
  for (int i = 0; i < n-1; ++i)
    if (buf[i] == buf[i+1]) return false;
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%s", buf);
  if (isUnique(buf)) puts("YES");
  else puts("NO");
  return 0;
}