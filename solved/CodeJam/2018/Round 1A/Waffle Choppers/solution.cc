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

int get_sum(vector<vector<int>> &sum, int x1, int y1, int x2, int y2) {
  x2++; y2++;
  return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

bool check_h(vector<vector<int>> &sum, vector<int> cuts, int target) {
  vector<int> vals(cuts.size() - 1);
  int n = sum.size() - 1;
  for (int i = 0; i < n; i++) {
    int all_equal = true;
    for (int c = 1; c < (int)cuts.size(); c++) {
      vals[c - 1] += get_sum(sum, i, cuts[c-1] + 1, i, cuts[c]);
      if (vals[c - 1] > target) {
        return false;
      }
      all_equal &= (vals[c-1] == target);
    }

    if (all_equal) {
      fill(vals.begin(), vals.end(), 0);
    }
  }
  return true;
}

void solve() {
  int n, m, h, v;
  read(n, m, h, v);
  vector<vector<char>> g(n, vector<char>(m));
  read(g);

  vector<vector<int>> sum(n + 1, vector<int>(m + 1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum[i + 1][j + 1] = g[i][j] == '@';
      sum[i + 1][j + 1] += sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
    }
  }

  int all = get_sum(sum, 0, 0, n - 1, m - 1);

  int cur = 0;
  int ok = (all % (v + 1)) == 0;
  int target = all / (v + 1);

  vector<int> cut;
  cut.push_back(-1);

  for (int j = 0; ok && j < m; j++) {
    if (cur + get_sum(sum, 0, j, n - 1, j) > target) {
      ok = false;
      break;
    }
    cur += get_sum(sum, 0, j, n - 1, j);
    if (cur == target) {
      if (target % (h + 1)) ok = false;
      else {
        cut.push_back(j);
        cur = 0;
      }
    }
  }

  if (ok) {
    ok &= check_h(sum, cut, target / (h + 1));
  }

  if (ok)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
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

