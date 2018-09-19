/*
 * 前序后序无法确定唯一二叉树的关键在于
 * 只有单子树的结点有两种可能性
 * 解决方法是找到前序中的'AB'
 * 后序中有多少个'BA'
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
  string pre, back;
  cin >> pre >> back;
  int count;
  string str;
  for (int i = 0; i < len1; i++) {
    for (int j = len2 - 1; j >= 0; j--) {
      if (pre[i] == suf[j]) {
        if (j != 0 && i != len1 - 1 && pre[i + 1] == suf[j - 1]) cnt++;
        break;
      }
    }
  }
  cout << pow(2, count) << endl;
  return 0;
}