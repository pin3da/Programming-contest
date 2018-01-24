#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);

  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  vector<int> ans(2);
  for (int i = 0; i < min(n, m); i++) {
    ans[a[i] <= b[i]]++;
  }

  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}
