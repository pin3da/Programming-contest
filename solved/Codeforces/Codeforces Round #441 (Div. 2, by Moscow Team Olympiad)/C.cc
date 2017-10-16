#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int sum_dig(int x) {
  int ans = x;
  while (x) {
    ans += (x % 10);
    x /= 10;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long x;
  cin >> x;
  vector<long long> ans;
  for (int i = 0; i <= 81; i++) {
    long long  y = x - i;
    if (sum_dig(y) == x) {
      ans.push_back(y);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto &i : ans)
    cout << i << endl;

  return 0;
}
