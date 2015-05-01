using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x)  << endl

void solve() {
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }
  int ans = 0;
  sort(num.begin(), num.end());
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cur  = num[i] + num[j];
      int id   = lower_bound(num.begin(), num.end(), cur) - num.begin();
      ans += max(0, id - j - 1);
    }
  }
  printf("%d\n", ans);
}
int main () {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
