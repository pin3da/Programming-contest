using namespace std;
#include <bits/stdc++.h>

inline void solve() {
  double a, r;
  cin >> a >> r >> r >> r;
  printf("%.10lf\n", a * sqrt(r / (1 + r)));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
