#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> p(n);
    int t;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> t;
        p[j] += t;
      }
    }

    int mmax = -1, ans;
    for (int i = n - 1; i >= 0; --i) {
      if (p[i] > mmax) {
        ans = i;
        mmax = p[i];
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
