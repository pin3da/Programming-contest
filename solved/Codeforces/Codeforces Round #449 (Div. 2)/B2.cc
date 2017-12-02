#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

long long eval(string s, long long p) {
  long long ans = 0;
  for (auto it : s) {
    ans = (ans * 10) % p;
    ans = (ans + it - '0') % p;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, p;
  cin >> n >> p;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    string cur = to_string(i);
    string inv = cur;
    reverse(inv.begin(), inv.end());
    ans = (ans + eval(cur + inv, p)) % p;
  }
  cout << ans << endl;
  return 0;
}
