using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int best = 1000001;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      best = min(best, b[i] - a[i]);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = max(i - best, 0); abs(j - i) <= best && j < n; ++j) {
        best = min(best, abs(i - j) + abs(a[i] - b[j]));
      }
    }

    cout << "K prechodu reky je treba " << best << " pontonu." << endl;
  }

  return 0;
}
