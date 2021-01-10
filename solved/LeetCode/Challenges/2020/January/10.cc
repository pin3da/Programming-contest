#include <bits/stdc++.h>

using namespace std;

#include "../../../template.cc"

using int64 = long long int;

// Single modification, range query.
struct SegTree {
  int n;
  vector<int> t;

  SegTree(int N) : n(N), t(2 * N) {}

  void add(int p, int value) {
    for (t[p += n] += value; p > 1; p >>= 1) {
      t[p>>1] = t[p] + t[p^1];
    }
  }

  // sum on interval [l, r)
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};


class Solution {
 public:
  int64 mod = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
      int mmax = (*max_element(instructions.begin(), instructions.end())) + 10;
      SegTree tree(mmax + 1);
      int ans = 0;
      for (auto val: instructions) {
        int cur = min(tree.query(0, val), tree.query(val + 1, mmax));
        ans = (ans + cur) % mod;
        tree.add(val, 1);
      }
      return ans;
    }
 private:

};

struct Test {
  vector<int> instructions;
  int expected;
};

int main() {
  vector<Test> test = {
    { {1,5,6,2}, 1},
    { {1,2,3,6,5,4}, 3},
    { {1,3,3,3,2,4,2,1,2}, 4},
    { {1,2,1,2,1,2,1,2,1,2,1,2}, 0}
  };
  for (auto t : test) {
    Solution sol;
    int actual = sol.createSortedArray(t.instructions);
    debug(t.instructions, t.expected, actual);
    assert(t.expected == actual);
  }
  return 0;
}
