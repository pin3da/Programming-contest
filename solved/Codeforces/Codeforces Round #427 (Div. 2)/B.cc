#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int sum; cin >> sum;
  string num; cin >> num;

  sort(num.begin(), num.end());
  int cur = 0;
  for (auto i : num) {
    cur += (i - '0');
  }

  int ans = 0;
  if (cur < sum) {
    for (int i = 0; i < (int) num.size(); ++i) {
      int can = '9' - num[i];
      cur += can;
      ans++;
      if (cur >= sum) break;
    }
  }
  cout << ans << endl;

  return 0;
}
