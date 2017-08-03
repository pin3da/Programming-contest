#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<double> p_diff(50000 * 2 + 100);
  sort(a.begin(), a.end());
  double den = (n * (n - 1)) * 0.5;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      p_diff[a[i] - a[j]] += 1.0 / den;

  vector<double> p_two(p_diff.size() * 2 + 100);

  int max_diff = 5000;
  for (int i = 0; i <= max_diff; i++) {
    for (int j = 0; j <= max_diff; j++) {
      p_two[i + j] += p_diff[i] * p_diff[j];
    }
  }

  double ans = 0;
  for (int i = 0; i <= max_diff; i++)
    for (int j = 0; j < i; j++)
    ans += p_diff[i] * p_two[j];

  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
