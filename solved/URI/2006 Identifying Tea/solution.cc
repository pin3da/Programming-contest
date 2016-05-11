#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t, ans = 0; cin >> t;
  vector<int> a(5); for (auto &i : a) { cin >> i; ans += i == t; }
  cout << ans << endl;

  return 0;
}
