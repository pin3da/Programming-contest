#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

const int MN = 555;

int p[MN];
int s[MN];

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  if (fs(x) == fs(y))
    return;
  s[fs(y)] += s[fs(x)];
  p[fs(x)] = fs(y);
}

int N;
const long long mod = 10000 * 10000;

long long dp[MN][MN];

long long go(vector<int> &a, int i, int acc) {
  if (a.size() == i) {
    return acc == N;
  }
  if (dp[i][acc] == -1) {
    long long ans = go(a, i + 1, acc);
    if (acc + a[i] <= N)
      ans = (ans + go(a, i + 1, acc + a[i])) % mod;
    dp[i][acc] = ans;
  }
  return dp[i][acc];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    N = n;
    n += n;
    vector<vector<int>> g(n, vector<int> (n, 1));
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--;v--;
      g[u][v] = g[v][u] = 0;
    }

    for (int i = 0; i < n; ++i)
      p[i] = i, s[i] = 1;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (g[i][j])
          js(i, j);

    unordered_map<int, int> cod;
    for (int i = 0; i < n; ++i)
      cod[fs(i)] = s[fs(i)];

    vector<int> a(cod.size());
    vector<int> b(cod.size());
    int j = 1;
    for (auto  &i : cod) {
      if (i.first == fs(0))
        a[0] = i.second, b[0] = fs(0);
      else {
        a[j] = i.second;
        b[j++] = i.first;
      }
    }

    memset(dp, -1, sizeof dp);
    cout << go(a, 1, a[0]) << endl;
    set<int> groups;
    groups.insert(fs(0));

    int i = 1, acc = s[fs(0)];
    while (acc != N) {
      long long op1 = dp[i + 1][acc];
      if (op1 > 0) {
        i++;
        continue;
      }
      acc += a[i];
      groups.insert(b[i]);
      i++;
    }

    assert(acc == N);
    int first = 0;
    for (int i = 0; i < n; ++i) {
      if (groups.count(fs(i))) {
        if (first) cout << " ";
        cout << i + 1;
        first = 1;
      }
    }
    cout << endl;
  }
  return 0;
}
