#include <vector>
#include <set>
#include <cassert>
#include <limits>
#include <iostream>

using namespace std;

template<class T>
class SlidingWindow {
  multiset<T> tree;
  public:
    SlidingWindow() {}

    void Remove(T x) {
      tree.erase(tree.find(x));
    }

    T Add(T x) {
      tree.insert(x);
      auto prev = tree.find(x);
      T best = numeric_limits<T>::max();
      if (tree.count(x) > 1)
        return 0;

      if (prev != tree.begin()) {
        prev--;
        best = x - *(prev);
      }
      auto next = tree.find(x);
      if (next != tree.end()) {
        next++;
        if (next != tree.end()) {
          best = min(best, *(next) - x);
        }
      }
      return best;
    }
};

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      SlidingWindow<long long> window;
      int n = nums.size();
      long long current = 0;
      k++;
      for (int i = 0; i < n && i < k; i++) {
        current = window.Add(nums[i]);
        if (i && current <= t)
          return true;
      }


      for (int i = k; i < n; i++) {
        window.Remove(nums[i - k]);
        current = window.Add(nums[i]);
        if (current <= t)
          return true;
      }

      return false;
    }
};


int main() {

  Solution sol;
  vector<int> nums = {1, 2, 3, 1};
  assert(sol.containsNearbyAlmostDuplicate(nums, 3, 0));

  nums = {1, 0, 1, 1};
  assert(sol.containsNearbyAlmostDuplicate(nums, 1, 2));

  nums = {1, 5, 9, 1, 5, 9};
  assert(!sol.containsNearbyAlmostDuplicate(nums, 2, 3));

  nums = {-1, 2147483647};
  assert(!sol.containsNearbyAlmostDuplicate(nums, 1, 2147483647));
  return 0;
}
