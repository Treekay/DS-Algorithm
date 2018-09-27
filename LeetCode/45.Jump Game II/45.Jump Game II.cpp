#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  Solution() {}

  int jump1(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size() - 1;
    int cur = 0;
    vector<int> steps(nums.size(), nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (steps[cur] >= nums.size() - 1) return cur + 1;
      steps[cur + 1] = max(i + nums[i], steps[cur + 1]);
      if (i >= steps[cur]) cur++;
    }
  }
  
};

int main(void) {
  Solution s;
  std::vector<int> v;

  while(1) {
    int num;
    cin >> num;
    if (num != 0) v.push_back(num);
    else break;
  }

  cout << s.jump(v) << endl;

  return 0;
}