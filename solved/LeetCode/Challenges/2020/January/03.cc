#include<bits/stdc++.h>

using namespace std;

bool IsDiv(int a, int b) {
  if (b == 0) {
    return false;
  }
  return (a % b) == 0;
}

class Solution {
  using Mask = bitset<15>;
  int n;
  vector<int> seen;
  int dp(Mask mask) {
    if (mask.count() == n) {
      return 1;
    }
    if (seen[mask.to_ulong()] != -1) {
      return seen[mask.to_ulong()];
    }
    int ans = 0;
    int pos = mask.count() + 1;
    for (int i = 0; i < n; i++) {
      int val = i + 1;
      if (mask[i] == 0 && (IsDiv(val, pos) || IsDiv(pos, val))) {
        Mask next = mask;
        next.set(i);
        ans += dp(next);
      }
    }
    seen[mask.to_ulong()] = ans;
    return ans;
  }

 public:
  int countArrangement(int n) {
    seen.assign((1 << 15) + 10, -1);
    this->n = n;
    return dp(Mask());
  }
};
