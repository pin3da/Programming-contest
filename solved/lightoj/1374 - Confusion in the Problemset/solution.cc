using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= n) {
      puts("no");
      return;
    }
    if (ans[a[i]] == 0)
      ans[a[i]]++;
    else if (ans[n - 1 - a[i]] == 0)
      ans[n - 1 - a[i]]++;
    else {
      puts("no");
      return;
    }
  }
  puts("yes");
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
