#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int query(vector<long long> &h, int start, int k) {
  int ans = start;
  int n = h.size();
  while (k > 0) {
    int j = ans;
    while (j < n && (j - ans) <= 100) {
      if (h[j] > h[ans]) {
        ans = j;
        break;
      }
      j++;
    }
    k--;
  }
  return ans;
}

void modify(vector<long long> &h, int l, int r, int x) {
  for (int i = l; i <= r; i++)
    h[i] += x;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> hills(n);
  for (auto &i : hills) cin >> i;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int i, k;
      cin >> i >> k;
      i--;
      cout << query(hills, i, k) + 1 << endl;
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      l--; r--;
      modify(hills, l, r, x);
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
