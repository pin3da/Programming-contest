#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int inf = 1000;
int dp[24 * 60][2][770][2];

int go(vector<int> &own, int t, int id, int t_first, int start) {
  if (t == int(own.size())) {
    if (t_first != 720) return inf;
    return id != start;
  }
  int best = inf;
  if (t_first > 720) return inf;
  if (dp[t][id][t_first][start] != -1) return dp[t][id][t_first][start];
  if (id == 0) {
    if (own[t] == 1) {
      best = min(best, go(own, t + 1, 1, t_first, start) + 1);
    } else if (own[t] == 0) {
      best = min(best, go(own, t + 1, 0, t_first + 1, start));
    } else {
      best = min(best, go(own, t + 1, 1, t_first, start) + 1);
      best = min(best, go(own, t + 1, 0, t_first + 1, start));
    }
  } else {
    if (own[t] == 0) {
      best = min(best, go(own, t + 1, 0, t_first + 1, start) + 1);
    } else if (own[t] == 1) {
      best = min(best, go(own, t + 1, 1, t_first, start));
    } else {
      best = min(best, go(own, t + 1, 1, t_first, start));
      best = min(best, go(own, t + 1, 0, t_first + 1, start) + 1);
    }
  }
  return dp[t][id][t_first][start] = best;
}

void solve() {
  int ac, aj;
  cin >> ac >> aj;
  vector<pair<int, int>> d1(ac), d2(aj);
  vector<int> own(24 * 60, -1);
  for (auto &i : d1) {
    cin >> i.first >> i.second;
    for (int j = i.first; j < i.second; ++j) own[j] = 0;
  }
  for (auto &i : d2) {
    cin >> i.first >> i.second;
    for (int j = i.first; j < i.second; ++j) own[j] = 1;
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", min(go(own, 0, 0, 0, 0), go(own, 0, 1, 0, 1)));
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
