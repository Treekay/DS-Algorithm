#include <iostream>
#include <map>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  map<int, int> num_map;
  int num;
  while (n--) {
    cin >> num;
    if (num_map.find(num) == num_map.end()) {
      num_map[num] = 1;
    }
    else {
      num_map[num]++;
    }
  }
  int max, val;
  n = num_map.size();
  for (int i = 0; i < n; i++) {
    max = 0;
    val = 0;
    for (map<int,int>::iterator iter = num_map.begin(); iter != num_map.end(); iter++) {
      if (iter->second > max) {
        val = iter->first;
        max = iter->second;
      }
      if (iter->second == max && iter->first < val) {
        val = iter->first;
      }
    }
    cout << val << ' ' << max << endl;
    num_map.erase(num_map.find(val));
  }
  return 0;
}