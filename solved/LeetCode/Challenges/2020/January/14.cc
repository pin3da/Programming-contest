
#include <bits/stdc++.h>

using namespace std;

#include "../../../template.cc"

using int64 = long long int;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int target = accumulate(nums.begin(), nums.end(), 0) - x;
      int j = 0;
      int best = -1;
      int acc = 0;
      for (int i = 0; i < nums.size() && j < nums.size(); i++) {
        while (j < nums.size() && acc < target) {
          acc += nums[j];
          j++;
        }
        if (acc == target) {
          best = max(best, j - i);
        }
        acc -= nums[i];
      }
      if (best == -1) {
        return best;
      }
      return nums.size() - best;
    }
};

struct Test {
  vector<int> nums;
  int x;
  int expected;
};

int main() {
  vector<Test> test = {
    { {1,1,4,2,3}, 5, 2},
    { {5,6,7,8,9}, 4, -1},
    { {3,2,20,1,1,3}, 10, 5},
  };
  for (auto t : test) {
    Solution sol;
    int actual = sol.minOperations(t.nums, t.x);
    debug(t.nums, t.x, t.expected, actual);
    assert(t.expected == actual);
  }
  return 0;
}
