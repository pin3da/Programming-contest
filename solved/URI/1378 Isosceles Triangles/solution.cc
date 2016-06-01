#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
      cin >> x[i] >> y[i];

    unordered_map<long long, long long> frec;
    long long ans = 0;
    frec.reserve(n);
    for (int i = 0; i < n; ++i) {
      frec.clear();
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        long long a = x[i] - x[j],
                  b = y[i] - y[j];
        long long dist = a * a + b * b;
        frec[dist]++;
      }
      for (auto &j : frec) {
        ans += (j.second * (j.second - 1)) / 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
