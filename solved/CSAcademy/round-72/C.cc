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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  read(a);

  vector<long long> sum_row(n);
  vector<long long> sum_col(m);

  for (int i = 0; i < n; i++) {
    sum_row[i] = accumulate(a[i].begin(), a[i].end(), 0LL);
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      sum_col[i] += a[j][i];

  long long cur = 0;
  for (int i = 0; i < n; i++) {
    cur += sum_row[i] * 2;
  }
  for (int i = 1; i + 1 < m; i++) {
    cur += (sum_col[i] - a[0][i] - a[n - 1][i]) * 2;
  }

  cur -= a[0][0] + a[0][m - 1] + a[n - 1][0] + a[n - 1][m - 1];

  long long ori = cur;
  debug(cur);
  for (int i = 1; i + 1 < n; i++) {
    long long opt = ori;
    opt += -2 * sum_row[i] + a[i][0] + a[i][m - 1];
    opt += 2 * sum_row[0] - a[0][0] - a[0][m - 1];
    cur = max(cur, opt);

    opt = ori;
    opt += -2 * sum_row[i] + a[i][0] + a[i][m - 1];
    opt += 2 * sum_row[n - 1] - a[n - 1][0] - a[n - 1][m - 1];
    cur = max(cur, opt);
  }

  for (int i = 1; i + 1 < m; i++) {
    long long opt = ori;
    opt += -2 * sum_col[i] + a[0][i] + a[n - 1][i];
    opt += 2 * sum_col[0] - a[0][0] - a[n - 1][0];
    cur = max(cur, opt);


    opt = ori;
    opt += -2 * sum_col[i] + a[0][i] + a[n - 1][i];
    opt += 2 * sum_col[m - 1] - a[0][m - 1] - a[n - 1][m - 1];
    cur = max(cur, opt);

  }

  cout << cur << endl;
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

