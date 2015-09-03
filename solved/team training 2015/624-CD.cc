#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  while (cin >> m) {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans1 = -1, ans2;
    for (int bm = 0; bm < (1 << n); bm++) {
      int sum = 0;
      bool flag = true;
      for (int i = 0; i < n && flag; i++) {
	if (sum <= m) {
	  if (bm & (1 << i))
	    sum += a[i];
	}
	else
	  flag = false;
      }

      if (!flag || sum > m)
	continue;

      if (sum > ans1 || (sum == ans1 && __builtin_popcount(bm) > __builtin_popcount(ans2))) {
	ans1 = sum;
	ans2 = bm;
      }
    }

    for (int i = 0; i < n; i++) {
      if (ans2 & (1LL << i))
	cout << a[i] << " ";
    }

    cout << "sum:" << ans1 << endl;
  }

  return 0;
}
