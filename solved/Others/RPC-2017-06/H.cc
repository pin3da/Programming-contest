#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int N = 1000000 + 1000;

struct seg_tree {
  int n;
  long long t[2 * N];

  void clear() {
    memset(t, 0, sizeof t);
  }

  // Single modification, range query.
  void add(int p, int value) {  // set value at position p
    for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};

seg_tree tree;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while(cin >> n && n) {
    vector<pair<int, int>> arr(n);
    vector<int> conv(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
      conv[arr[i].second] = i + 1;
    }

    tree.clear();
    tree.n = n + 100;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = tree.query(conv[i], n + 1);
      ans += tmp;
      tree.add(conv[i], 1);
    }
    cout << ans << endl;
  }
  return 0;
}
