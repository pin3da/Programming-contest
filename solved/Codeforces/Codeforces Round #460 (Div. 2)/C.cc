#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << to_string(h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

long long solve(vector<vector<int>> &b, int k) {
  int n = b.size(), m = b[0].size();

  vector<int> s(m + 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s[j + 1] = b[i][j];
      s[j + 1] += s[j];
    }
    for (int j = 0; j + k <= m; j++) {
      if ((s[j + k] - s[j]) == 0)
        ans++;
    }
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> b(n, vector<int>(m));
  for (auto &it : b) for (auto &i : it) {
    char t;
    cin >> t;
    i = (t == '*');
  }
  long long ans = solve(b, k);

  vector<vector<int>> bb(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bb[j][i] = b[i][j];
    }
  }

  if (k > 1)
    ans += solve(bb, k);

  cout << ans << endl;

  return 0;
}
