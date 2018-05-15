#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(vector<vector<char>> &b, int x, int y) {
  if (b[x][y] == '*') return true;
  int count = 0;
  for (int k = 0; k < 8; k++) {
    int nx = x + dx[k], ny = y + dy[k];
    if (nx >= 0 && nx < int(b.size()) && ny >= 0 && ny < int(b[0].size())) {
      count += b[nx][ny] == '*';
    }
  }

  if (b[x][y] == '.')
    return count == 0;

  if (isdigit(b[x][y]))
    return count == (int)(b[x][y] - '0');
  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> board(n, vector<char> (m));
  read(board);

  int ok = true;
  for (int i = 0; i < n && ok; i++) {
    for (int j = 0; j < m && ok; j++) {
      ok &= valid(board, i, j);
    }
  }
  puts(ok ? "YES" : "NO");
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

