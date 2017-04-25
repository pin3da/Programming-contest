// http://codeforces.com/contest/624/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a)
    cin >> i;

  sort(a.rbegin(), a.rend());

  long long ans = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] >= a[i - 1])
      a[i] = a[i - 1] - 1;
    ans += max<long long> (0, a[i]);
  }
  cout << ans << endl;

  return 0;
}
