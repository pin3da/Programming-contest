#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n / 2);
  for (auto &i : a) cin >> i;

  sort(a.begin(), a.end());

  int a1 = 0, a2 = 0, j = 0;
  for (int i = 1; i <= n; i+= 2)
    a1 += abs(a[j++] - i);
  j = 0;
  for (int i = 2; i <= n; i+= 2)
    a2 += abs(a[j++] - i);
  cout << min(a1, a2) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

