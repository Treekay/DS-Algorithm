#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindromic(string s) {
    for (int i = 0; i < s.length()/2; i++) {
      if (s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
  }

  string longestPalindrome(string s) {

  }
};

int main(void) {
  Solution s;
  string str;
  cout << s.longestPalindrome(str) << endl;
  return 0;
}