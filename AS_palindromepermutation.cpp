// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// Every characters should appear even times, but at most 1 character can appear odd time.
// Just iterate from left to right and count
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>

using namespace std;

const int NUMCHARS = 256;

string s;

bool checkPalindromePermutation(string & s) {
  bool check[NUMCHARS] = {0};
  for (int i = 0; i < s.length(); ++i)
    check[s[i]] ^= 1;
  
  int numberOfTrue = 0;
  for (int i = 0; i < NUMCHARS; ++i)
    numberOfTrue += check[i];
  return numberOfTrue <= 1;
}

int main() {
  freopen("input.txt" ,"r", stdin);
  getline(cin, s);
  cout << (checkPalindromePermutation(s) ? "YES" : "NO") << endl;
  return 0;
}