#include<bits/stdc++.h>
using namespace std;

const long long inf = 1LL << 40;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    long long mmin = inf;
    long long u, d;
    for (int i = 0; i < m; ++i) {
      cin >> u >> d;
      long long a = ((d * n) / (u + d)) + 1;
      long long b = n - a;
      mmin = min(mmin, a * u - b * d);
    }
    cout << mmin << endl;
  }
  return 0;
}
