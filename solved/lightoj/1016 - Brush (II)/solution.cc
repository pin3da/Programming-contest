using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n, w;
  scanf("%d%d", &n, &w);

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x.begin() + i, y.begin() + i);
  }
  sort(y.begin(), y.end());
  int i = 0, j = 1;
  int ans = 1;
  while (i < n) {
    while (j < n && (y[j] - y[i]) <= w) ++j;
    if (j >= n)
      break;
    i = j;
    ans++;
  }
  printf("%d\n", ans);
}


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
