#include <vector>
#include <map>

using namespace std;

class Solution {

  map<pair<int, int>, bool> dp;

  int findNextPos(vector<int> &stones, int pos, int jump) {
    int target = stones[pos] + jump;
    auto it = lower_bound(stones.begin(), stones.end(), target);
    if (it != stones.end() && (*it) == target) {
      return it - stones.begin();
    }
    return -1;
  }

  bool canCrossDP(vector<int> &stones, int pos, int jump) {
    if (pos == (int(stones.size()) - 1)) {
      return true;
    }

    if (jump == 0) return false;

    pair<int, int> state = make_pair(pos, jump);
    if (dp.count(state))
      return dp[state];

    bool possible = false;
    int next_pos = findNextPos(stones, pos, jump);
    if (next_pos != -1) {
      possible = canCrossDP(stones, next_pos, jump + 1);
      possible |= canCrossDP(stones, next_pos, jump);
      if (jump > 0) {
        possible |= canCrossDP(stones, next_pos, jump - 1);
      }
    }

    dp[state] = possible;
    return possible;
  }

  public:
    bool canCross(vector<int>& stones) {
      dp.clear();
      return canCrossDP(stones, 0, 1);
    }
};
