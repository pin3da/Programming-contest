#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> dp;
  int go(string &s, int id) {
    if (id == (int)s.size())
      return 1;

    if (dp[id] != -1)
      return dp[id];

    int ways = 0;
    if (s[id] == '0')
      return dp[id] = 0;

    if (id + 1 < int(s.size())) {
      if ((s[id] < '2') || (s[id] == '2' && s[id + 1] <= '6'))
        ways += go(s, id + 2);
    }
    ways += go(s, id + 1);
    return dp[id] = ways;
  }

  public:
  int numDecodings(string s) {
    dp = vector<int>(s.size(), -1);
    return go(s, 0);
  }
};

int main() {

  Solution sol;
  assert(sol.numDecodings("12") == 2);
  assert(sol.numDecodings("226") == 3);
  assert(sol.numDecodings("101") == 1);
  assert(sol.numDecodings("0") == 0);

  return 0;
}
