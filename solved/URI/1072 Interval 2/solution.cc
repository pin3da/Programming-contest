#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t, ans = 0;
  long long x;
  cin >> t;
  for (int i = 0; i < t; ++i)
    if (cin >> x && x >= 10 && x <= 20)
      ans++;

  cout << ans << " in" << endl;
  cout << t - ans << " out" << endl;
  return 0;
}
