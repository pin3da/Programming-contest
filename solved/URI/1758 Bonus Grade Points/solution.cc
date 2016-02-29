#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int crit(double a) {
  if (a >= 7.0) return 0;
  if (a >= 4.0) return 1;
  return 2;
}

void solve() {
  int n, p;
  cin >> p >> n;
  vector<vector<double>> a(n, vector<double>(p));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j)
      cin >> a[i][j];
  }

  for (int i = 0; i < n; ++i) {
    double av = accumulate(a[i].begin(), a[i].end(), 0.0) / (double) a[i].size();
    if (crit(av) < 2) {
      sort(a[i].begin(), a[i].end());
      for (int j = 0; j < a[i].size(); ++j) {
        double b = a[i][j];
        if (crit(b) == crit(av))
          av = max(av, b);
      }
    }
    cout << fixed << setprecision(2) << av << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--)
    solve();

  return 0;
}

