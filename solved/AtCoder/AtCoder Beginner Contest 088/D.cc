#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> b(h, vector<char> (w, -1));

  int black = 0;
  for (auto &it : b)
    for(auto &i : it) {
      cin >> i;
      if (i == '#') black++;
    }

  deque<pair<int, int>> q;
  q.emplace_back(0, 0);
  vector<vector<int>> d(h, vector<int> (w, 1000));

  d[0][0] = 1;
  while (!q.empty()) {
    auto cur = q.front(); q.pop_front();

    for (int k = 0; k < 4; k++) {
      int x = cur.first + dx[k];
      int y = cur.second + dy[k];
      if (x >= 0 && x < h && y >= 0 && y < w) {
        if (b[x][y] != '#' && d[cur.first][cur.second] + 1 < d[x][y]) {
          d[x][y] = d[cur.first][cur.second] + 1;
          q.emplace_back(x, y);
        }
      }
    }
  }
  if (d[h - 1][w - 1] < 1000) {
    cout << h * w - d[h - 1][w - 1] - black << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

