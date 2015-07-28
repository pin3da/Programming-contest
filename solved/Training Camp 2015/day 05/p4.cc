using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, t; cin >> n;
    int ans = 0;
    while (n--) {
      cin >> t;
      ans = __gcd(ans, t);
    }
    cout << ans << endl;
  }
  return 0;
}
