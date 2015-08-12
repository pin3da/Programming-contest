using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && a[j] != (i + 1)) j++;
    if (i != j) {
      swap(a[i], a[j]);
      ans++;
    }
  }
  printf("%d\n", ans);
}


int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
