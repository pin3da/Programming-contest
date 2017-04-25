// http://codeforces.com/contest/629/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;



struct seg_tree {
  vector<long long> m;
  seg_tree (int n) {
    m.assign(4 * n + 10, 0);
  }

  void update(int node, int b, int e, int pos, long long val) {
    if (b == e) {
      m[node] = val; return;
    }
    int mid = (b + e) >> 1;
    if (mid >= pos) update(node << 1, b, mid, pos, val);
    else            update(node << 1 | 1, mid + 1, e, pos, val);
    m[node] = max(m[node << 1], m[node << 1 | 1]);
  }

  long long query(int node, int b, int e, int l, int r) {
    if ( b >= l && e <= r)
      return m[node];
    if (e < l || b > r ) return 0;
    int mid = (b + e) >> 1;
    return  max(query(node << 1, b, mid, l, r), query(node << 1 | 1, mid + 1, e, l, r));
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  long long r, h;
  while (cin >> n) {

    vector<long long> v(n);
    vector<long long> v2(n);
    for (int i = 0; i < n; ++i) {
      cin >> r >> h;
      v2[i] = v[i] = r * r * h;
    }

    sort(v2.begin(), v2.end());
    unordered_map<long long, int> cod;
    unordered_map<int, long long> dec;

    cod.reserve(n + 10);
    dec.reserve(n + 10);

    for (int i = 0; i < v2.size(); ++i) {
      cod[v2[i]] = i + 1;
      dec[i + 1] = v2[i];
    }

    int m = n + 1;
    seg_tree tree(m);

    vector<long long> dp(n + 1);
    dp[0] = 0;

    for (int ii = 1; ii <= n; ++ii) {
      int i = ii - 1;
      dp[ii] = tree.query(1, 0, m, 0, cod[v[i]] - 1) + v[i];
      tree.update(1, 0, m, cod[v[i]], dp[ii]);
    }

    long long best = tree.query(1, 0, m, 0, m);
    cout << fixed << setprecision(12) << acos(-1) * best << endl;

  }

  return 0;
}