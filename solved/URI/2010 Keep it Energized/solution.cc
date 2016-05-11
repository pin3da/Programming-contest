#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int N = 1e5 + 100;  // limit for array size
int n;  // array size
long long t[2 * N];
const long long inf = 1LL << 40;

// Single modification, range query.
void modify(int p, long long value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

long long query(int l, int r) {  // sum on interval [l, r)
  long long res = inf;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res, t[--r]);
  }
  return res;
}

vector<long long> cost;
vector<vector<long long>> s, p;


long long getsum(int i, int j) {
  if (j < i) return 0;
  long long ans = cost[j];
  if (i)
    return ans - cost[i - 1];
  return ans;
}

long long add(long long x, long long y) {
  x += y;
  if (x > inf)
    return inf;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  while (cin >> n >> m) {
    cost.assign(n, 0);
    s.assign(n, vector<long long> ());
    p.assign(n, vector<long long> ());
    for (auto &i : cost) cin >> i;
    for (int i = 0; i < m; ++i) {
      int id; cin >> id;
      id--;
      long long str, pri;
      cin >> str >> pri;
      s[id].emplace_back(str);
      p[id].emplace_back(pri);
    }
    for (int i = 1; i < n; ++i)
      cost[i] += cost[i - 1];

    memset(t, 0, sizeof 0);
    modify(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      long long start = getsum(0, i - 1);
      modify(i, inf);
      for (int k = 0; k < s[i].size(); ++k) {
        long long additional = s[i][k];
        int j = upper_bound(cost.begin(), cost.end(), start + additional) - cost.begin();
        if (j > i)
          if (add(query(i + 1, j + 1),  p[i][k]) < query(i, i + 1))
            modify(i, add(query(i + 1, j + 1),  p[i][k]));
      }
    }
    long long ans = query(0, 1);
    if (ans < inf)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
