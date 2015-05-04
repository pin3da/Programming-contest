using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf = 1 << 30;

int dist(deque<pair<int, int> > &pos, int a, int b) {
  int x1 = pos[a].first, x2 = pos[b].first;
  int y1 = pos[a].second, y2 = pos[b].second;
  return max(fabs(x1 - x2), fabs(y1 -y2));
}

int dp[(1 << 16) + 10][20];

int go(deque<pair<int, int> > &pos, int mask, int bef) {
  if (dp[mask][bef] != -1)
    return dp[mask][bef];

  if (mask == (1 << pos.size()) - 1) {
    return dp[mask][bef] = dist(pos, bef, 0);
  }

  int best = inf;
  for (int i = 0; i < pos.size(); ++i) {
    if (!((mask >> i) & 1)) {
      best = min(best, go(pos, mask | (1 << i), i) + dist(pos, bef, i));
    }
  }
  return dp[mask][bef] = best;
}

void solve() {
  int n, m;
  cin >> n >> m;
  deque<pair<int, int> > pos;
  char c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      if (c == 'x')
        pos.push_front(make_pair(i, j));
      else if (c == 'g')
        pos.push_back(make_pair(i, j));
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", go(pos, 1, 0));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
