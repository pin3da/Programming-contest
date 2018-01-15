#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

long long best(vector<int> &a) {
  long long ans = a[0], ant = a[0];

  for (int i = 1; i < (int)a.size(); i++) {
    ant = max<long long>(ant + a[i], a[i]);
    ans = max(ans, ant);
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  if (k == 1) {
    cout << best(a) << endl;
    return;
  }

  vector<int> b;
  for (int i = 0; i < 2; i++)
    for (auto it : a)
      b.push_back(it);

  long long ans = best(b);
  long long extra = accumulate(a.begin(), a.end(), 0LL);

  if (extra > 0)
    ans += extra * max(0, k - 2);

  cout << ans << endl;
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
