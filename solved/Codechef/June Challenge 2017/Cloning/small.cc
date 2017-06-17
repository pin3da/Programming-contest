#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


bool similar(vector<int> &f1, vector<int> &f2) {
  sort(f1.begin(), f1.end());
  sort(f2.begin(), f2.end());
  int num_diff = 0;
  for (int i = 0; i < (int)f1.size(); ++i)
    num_diff += (f1[i] != f2[i]);
  return num_diff < 2;
}

void solve() {
  int n, q; cin >> n >> q;
  vector<int> all(n);
  for (int &i : all) cin >> i;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;b--;c--;d--;
    vector<int> f1, f2;
    for (int i = a; i <= b; ++i) f1.push_back(all[i]);
    for (int i = c; i <= d; ++i) f2.push_back(all[i]);
    puts(similar(f1, f2) ? "YES" : "NO");
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while(tc--) solve();

  return 0;
}
