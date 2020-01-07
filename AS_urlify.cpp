// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: If implementing in Java, please use a character array so that you can perform this operation in place.) 
// Iterate from left to right and append %20 if current character is space, else just append the current character to the end of the result string
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>

using namespace std;

string URLify(string & s) {
  string res = "";
  for (int i = 0; i < s.length(); ++i)
    if (s[i] != ' ') res.push_back(s[i]);
    else res += "%20";
  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  getline(cin, s);
  cout << URLify(s) << endl;
  return 0;
}