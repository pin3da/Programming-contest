using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m + 1);
  for (int i = 0; i < m + 1; ++i) {
    cin >> a[i];
  }

  int last = a[m];
  int ans = 0;
  for (int i = 0; i < a.size() - 1; ++i) {
    a[i] ^= last;
    if ( __builtin_popcount(a[i]) <= k)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
