using namespace std;
#include <bits/stdc++.h>

vector<long long> gen(const vector<int> &a) {
  int n = 1 << a.size();
  vector<long long> ans;
  for (int mask = 0; mask < n; ++mask) {
    long long cur = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (mask >> i & 1)
        cur += a[i];
    }
    ans.push_back(cur);
  }
  return ans;
}
void solve() {
  int n, t;
  long long w;
  cin >> n >> w;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (i & 1)
      a.push_back(t);
    else
      b.push_back(t);
  }

  vector<long long> sa = gen(a);
  vector<long long> sb = gen(b);
  sort(sb.begin(), sb.end());

  long long ans = 0;
  for (int i = 0; i < sa.size(); ++i) {
    long long t = w - sa[i];
    ans += upper_bound(sb.begin(), sb.end(), t) - sb.begin();
  }
  printf("%lld\n", ans);
}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
