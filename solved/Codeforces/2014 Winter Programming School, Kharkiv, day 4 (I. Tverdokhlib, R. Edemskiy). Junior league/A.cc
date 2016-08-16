#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < i; ++j)
      if (a[i] < a[j]) ans++;
  }
  cout << ans << endl;

  return 0;
}
