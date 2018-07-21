#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

class Solution {
  class UniqueSet {
    vector<int> frec;
    int total;
    public:
    UniqueSet(int elements) : frec(elements), total(0) {}

    void insert(int x) {
      if (frec[x] == 0) total++;
      frec[x]++;
    }

    void erase(int x) {
      frec[x]--;
      if (frec[x] == 0) total--;
    }

    size_t size() {
      return total;
    }
  };

  vector<int> testLen(vector<vector<int>> &nums, int len) {
    vector<pair<int, int>> all;
    for (int i = 0; i < int(nums.size()); i++)
      for (auto it : nums[i])
        all.emplace_back(it, i);

    const int n = all.size();

    UniqueSet active(nums.size());
    sort(all.begin(), all.end());

    int j = 0;
    active.insert(all[j].second);
    j++;

    for (int i = 0; i < n; i++) {
      while (j < n && all[j].first <= (all[i].first + len)) {
        active.insert(all[j].second);
        j++;
      }
      if (active.size() == nums.size()) {
        return {all[i].first, all[i].first + len};
      }
      active.erase(all[i].second);
    }
    return {};
  }

  public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int lo = 0, hi = 200001;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      auto tmp = testLen(nums, mid);
      if (tmp.size()) hi = mid;
      else lo = mid + 1;
    }
    auto ans = testLen(nums, lo);
    assert(ans.size() == 2);
    return ans;
  }
};

int main() {
  vector<vector<int>> a;
  a.emplace_back(vector<int>({4,10,15,24,26}));
  a.emplace_back(vector<int>({0,9,12,20}));
  a.emplace_back(vector<int>({5,18,22,30}));

  Solution sol;
  auto ans = sol.smallestRange(a);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
