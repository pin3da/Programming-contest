#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

typedef vector<vector<int>> grid;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

grid next(grid &g) {
  grid ans(3, vector<int>(3));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int acc = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
          acc ^= g[nx][ny];
        }
      }

      ans[i][j] = acc;
    }
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) {
    grid g(3, vector<int>(3));
    for (auto &it : g)
      for (auto &i : it) {
        char t; cin >> t;
        i = t - '0';
      }

    set<grid> seen;
    seen.insert(g);
    int ans = -1;
    while (true) {
      grid gg = next(g);
      if (seen.count(gg))
        break;
      ans++;
      seen.insert(gg);
      g = gg;
    }
    cout << ans << endl;
  }
  return 0;
}
