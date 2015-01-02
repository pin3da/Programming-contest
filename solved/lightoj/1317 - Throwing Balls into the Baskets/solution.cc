using namespace std;
#include <bits/stdc++.h>


void solve() {
  int n, k;
  double p;
  cin >> n >> k >> k >> p;
  printf("%.14lf\n", n * p * k);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
