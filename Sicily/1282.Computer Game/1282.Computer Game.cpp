#include <iostream>
using namespace std;

int code_dimension;
int code[60000];
int protection_dimension;
int protection[1000000];
int Next[60000];

void next() {
  int current_code, current_pro;
  Next[0] = -1;
  current_code = 0;
  current_pro = -1;
  while (current_code < code_dimension - 1) {
    if (current_pro == -1 || code[current_code] == code[current_pro]) {
      current_code++;
      current_pro++;
      Next[current_code] = current_pro;
    }
    else {
      current_pro = Next[current_pro];
    }
  }
}

int kmp() {
  next();
  int current_code = 0;
  int current_pro = 0;
  while (current_code < protection_dimension) {
    if (current_pro == -1 || protection[current_code] == protection[current_pro]) {
      current_code++;
      current_pro++;
    }
    else {
      current_pro = Next[current_pro];
    }
    if (current_pro == code_dimension) return current_code - code_dimension;
  }
  return -1;
}

int main(void) {
  while (cin >> code_dimension && code_dimension != 0) {
    for (int i = 0; i < code_dimension; i++) {
      cin >> code[i];
    }
    cin >> protection_dimension;
    for (int i = 0; i < protection_dimension; i++) {
      cin >> protection[i];
    }
    int index = kmp();
    if (index == -1) cout << "no solution" << endl;
    else cout << index << endl;
  }
  return 0;
}
