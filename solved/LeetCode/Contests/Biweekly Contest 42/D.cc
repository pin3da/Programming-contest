#include <bits/stdc++.h>
#include "./template.cc"
using namespace std;

using int64 = long long;
class Solution {
  vector<int64> bestLeft(vector<int>& nums, int64 k) {
        int n = nums.size();
	int64 best = 10000000000;
	vector<int64> ans(n, best);
        deque<int64> pos;
        int64 acc = 0;
        int64 extra = ((k - 1) * (k) / 2);
        for (int64 i = 0; i < n; i++) {
            if (nums[i] == 1) {
                pos.push_back(i);
                acc += i;
            }
            if (pos.size() > k) {
                acc -= pos.front();
                pos.pop_front();
            }
            if (pos.size() == k) {
                ans[i] = i * k - acc - extra;
            }
	   
        }
        return ans;
    }

public:
    int minMoves(vector<int>& nums, int k) {
      int sL = k / 2;
      int sR = k - sL;
      auto left = bestLeft(nums, sL);
      reverse(nums.begin(), nums.end());
      auto right = bestLeft(nums, sR);
      reverse(right.begin(), right.end());
      int64 best = 10000000000;
      for (int i = 0; i + 1 < nums.size(); i++) {
        best = min(best, left[i] + right[i + 1]);
      }
      return best;
    }
};

struct Input {
    vector<int> n;
    int k;
};

int main() {
    vector<Input> in = {
        {
            {1,0,0,1,0,1}, 2
        },
        {
            {1,0,0,0,0,0,1,1}, 3
        },
        {
            {0,1,1,0,0,1,0,0,0}, 3
        },
        {
            {1,0,0,1,0,1,1,1,0,1,1}, 7
        }
    };

    for (auto &it : in) {
        Solution sol;
        print(cout, sol.minMoves(it.n, it.k));
    }
}
