// http://codeforces.com/contest/609/problem/A

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  int m; cin >> m;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.rbegin(), a.rend());

  int acc = 0, ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (acc < m) {
      acc += a[i];
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
