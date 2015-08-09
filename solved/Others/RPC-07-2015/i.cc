using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  int ans = n;
  for (int i = 0; i < n; ++i)
    ans = min(ans, a[i] + n - i - 1);

  cout << ans << endl;

  return 0;
}
