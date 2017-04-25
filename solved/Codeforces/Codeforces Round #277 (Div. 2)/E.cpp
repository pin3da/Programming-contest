// http://codeforces.com/contest/486/problem/E

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct seg_tree {
  vector<int> m;
  seg_tree (int n) {
    m.assign(4 * n + 10, 0);
  }

  void update(int node, int b, int e, int pos, int val) {
    if (b == e) {
      m[node] = val; return;
    }
    int mid = (b + e) >> 1;
    if (mid >= pos) update(node << 1, b, mid, pos, val);
    else            update(node << 1 | 1, mid + 1, e, pos, val);
    m[node] = max(m[node << 1], m[node << 1 | 1]);
  }

  int query(int node, int b, int e, int l, int r) {
    if ( b >= l && e <= r)
      return m[node];
    if (e < l || b > r ) return 0;
    int mid = (b + e) >> 1;
    return  max(query(node << 1, b, mid, l, r), query(node << 1 | 1, mid + 1, e, l, r));
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<int> dp(n);
  int m = *max_element(a.begin(), a.end()) + 1;
  seg_tree tree(m);

  tree.update(1, 0, m, a[0], 1);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i] = tree.query(1, 0, m, 0, a[i] - 1) + 1;
    tree.update(1, 0, m, a[i], dp[i]);
  }
  int best = tree.query(1, 0, m, 0, m);

  unordered_map<int, int> frec, last;
  vector<int> ans(n, 1);
  for (int i = n - 1; i >= 0; --i) {
    if (dp[i] == best || last.count(dp[i] + 1) && last[dp[i] + 1] > a[i]) {
      ans[i] = 3;
      frec[dp[i]]++;
      last[dp[i]] = max(last[dp[i]], a[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ans[i] == 3 && frec[dp[i]] > 1)
      ans[i] = 2;
    cout << ans[i];
  }
  cout << endl;

  return 0;
}