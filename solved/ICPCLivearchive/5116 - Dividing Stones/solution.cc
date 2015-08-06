using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

vector<long long> all;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };
int m;

void go(int n, int k, long long cur) {
  all.push_back(cur);
  for (int i = k; p[i] <= n; ++i)
    go(n - p[i], i, (cur * p[i]) % m);
}

void solve() {
  int n;
  cin >> n >> m;
  all.clear();
  go(n, 0, 1 % m);
  sort(all.begin(), all.end());
  int ans = unique(all.begin(), all.end()) - all.begin();
  cout << ans << endl;
}

int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
