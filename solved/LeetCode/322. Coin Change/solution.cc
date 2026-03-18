class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    state = vector<int>(amount + 1, INF);
    state[0] = 0;
    for (int64_t i = 0; i <= amount; i++) {
      if (state[i] == INF) {
        continue;
      }
      for (int coin : coins) {
        int64_t t = i + coin;
        if (t > amount) {
          continue;
        }
        state[t] = min(state[t], state[i] + 1);
      }
    }
    int ans = state[amount];
    return ans == INF ? -1 : ans;
  }

private:
  const int MAX_AMOUNT = 10000;
  const int INF = 1000000;
  vector<int> state;
};
