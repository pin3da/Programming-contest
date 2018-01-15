#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  vector<int> a(4);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int ok = (a[0] == a[1]) && (a[2] == a[3]);
  puts(ok ? "YES" : "NO");
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
