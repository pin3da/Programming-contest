using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  int n, t;
  cin >> n;
  vector<int> tree;
  int cur = 0;
  tree.push_back(cur);
  int mmin, mmax;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (i == 0) {
      mmin = t;
      mmax = t;
    }
    cur ^= t;
    for (int j = 0; j < tree.size(); ++j) {
      mmin = min(mmin, tree[j] ^ cur);
      mmax = max(mmax, tree[j] ^ cur);
    }
    tree.push_back(cur);
  }
  printf("%d %d\n", mmax, mmin);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
