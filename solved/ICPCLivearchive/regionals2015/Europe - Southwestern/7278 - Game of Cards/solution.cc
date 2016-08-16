#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 2000 + 100;
int dp[MN];

int go(vector<int> &p, int id, int k) {
  if (p.size() == id) return 0;
  assert(id < p.size());
  if (dp[id] != -1) return dp[id];

  int n = p.size() - id;
  int mmax = max(0, min(n - 1, k));
  vector<int> mex(22);
  for (int i = 0; i <= mmax; ++i) {
    int rem = i + p[id + i];
    if (rem > n) continue;
    int g = go(p, id + rem, k);
    mex[g] = true;
  }

  for (int i = 0; i < mex.size(); ++i)
    if (!mex[i]) {
      return dp[id] = i;
    }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int p, k;
  while (cin >> p >> k) {
    int ans = 0;
    for (int i = 0; i < p; ++i) {
      int n; cin >> n;
      vector<int> pile(n);
      for (int j = 0; j < n; ++j)
        cin >> pile[j];

      reverse(pile.begin(), pile.end());
      memset(dp, -1, sizeof dp);
      int g = go(pile, 0, k);
      ans ^= g;
    }
    puts(ans ? "Alice can win." : "Bob will win.");
  }

  return 0;
}
