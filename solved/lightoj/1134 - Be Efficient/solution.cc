using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<int> frec(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] %= m;
    if (i) a[i] = (a[i] + a[i - 1]) % m;
    frec[a[i]]++;
  }

  long long ans = frec[0];
  for (int i = 1; i < n; ++i) {
    frec[a[i - 1]]--;
    ans += frec[a[i - 1]];
  }
  printf("%lld\n", ans);
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
