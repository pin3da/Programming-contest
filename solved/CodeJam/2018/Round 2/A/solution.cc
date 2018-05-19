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

void solve() {
  int n; cin >> n;
  vector<int> data(n);
  read(data);

  if (accumulate(data.begin(), data.end(), 0) != n) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if ((data[0] == 0) || (data[n - 1] == 0)) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<vector<char>> ans(n + 10, vector<char> (n, '.'));

  vector<int> up(n, 1);

  int carry = -1 * (data[0] - 1);
  int h = 1;
  for (int i = 1; i < n; i++) {
    if (data[i] == 0) {
      if (carry < 0) {
        ans[h][i] = '/';
      } else {
        ans[h][i] = '\\';
      }
      carry++;
    } else {
      if (carry < 0) {
        ans[h][i] = '/';
        up[i] = false;
      }
      carry++;
      carry = carry - data[i];
    }
  }

  if (ans[1][n - 1] != '.') {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for (int i = 1; i < n; i++) {
    if (ans[1][i - 1] == '\\' && ans[h][i] == '/' && (up[i])) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  while (true) {
    int stop = true;
    for (int i = 1; i < n; i++) {
      if ((ans[h][i - 1] == '/') && (ans[h][i] == '/') && up[i]) {
        ans[h + 1][i] = '/';
        stop = false;
      }
    }
    h++;
    if (stop) break;
  }



  int top = max(h, 1);
  h = 1;
  while (true) {
    int stop = true;
    for (int i = 0; i + 1 < n; i++) {
      if ((ans[h][i + 1] == '\\') && (ans[h][i] == '\\')) {
        ans[h + 1][i] = '\\';
        stop = false;
      }
    }
    h++;
    if (stop) break;
  }

  top = max(top, h);
  int empty = true;
  for (int i = 0; i < n; i++) {
    if (ans[top - 1][i] != '.') empty = false;
  }

  if (empty)
    top = max(top - 1, 1);

  cout << top << endl;
  for (int i = top - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

