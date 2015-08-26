using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = n - 1; i > 0; --i)
    a[i] -= a[i - 1];
  int t = *max_element(a.begin(), a.end());
  printf("%d\n", min(t + 1, (int)(t + count(a.begin(), a.end(), t) - 1)));
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
