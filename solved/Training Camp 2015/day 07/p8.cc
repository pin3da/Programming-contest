using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    long long ans = 0;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; ++i) {
      ans += a[i] * b[i];
    }
    cout << ans << endl;
  }
  return 0;
}
