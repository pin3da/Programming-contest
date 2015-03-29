using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct seg_tree {
  vector<long long> d;
  seg_tree(int n) {
    int k = 1;
    while (k < n)
      k <<= 1;
    d.resize(k << 1);
  }

  long long query(int node, int b, int e, int l, int r) {
    if (r < b || l > e)
      return 0;
    if (b >= l && e <= r)
      return d[node];

    long long p1 = query(node << 1, b, (b + e) >> 1, l, r);
    long long p2 = query((node << 1) + 1, ((b + e) >> 1) + 1, e, l, r);
    return max(p1, p2);
  }
  void update(int node, int b, int e, int pos, long long val) {
    if (pos < b || pos > e)
      return;
    if (pos == b && pos == e) {
      d[node] = val;
      return;
    }
    update(node << 1, b, (b + e) >> 1, pos, val);
    update((node << 1) + 1, ((b + e) >> 1) + 1, e, pos, val);
    d[node] = max(d[node << 1], d[(node << 1) + 1]);
  }
};

vector<int> lis(const vector<int> &a) {
  seg_tree tree(a.size() + 10);
  vector<int> dp(a.size());
  for (int i = 0; i < a.size(); ++i) {
    dp[i] = tree.query(1, 0, a.size() - 1, 0, a[i] - 1) + 1;
    tree.update(1, 0, a.size() - 1, a[i], dp[i]);
  }
  for (int i = 1; i < a.size(); ++i) {
    dp[i] = max(dp[i], dp[i - 1]);
  }
  return dp;
}

int main() {
#ifdef ONLINE_JUDGE
  freopen("improvements.in", "r", stdin);
  freopen("improvements.out", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> num(n);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      num[t - 1] = i;
    }
    vector<int> inc = lis(num);
    reverse(num.begin(), num.end());
    vector<int> dec = lis(num);
    reverse(dec.begin(), dec.end());
    int best = max(dec[0], inc.back());
    for (int i = 0; i < n - 1; ++i) {
      best = max(best, inc[i] + dec[i + 1]);
    }
    cout << best << endl;
  }
}

