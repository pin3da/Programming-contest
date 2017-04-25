// http://codeforces.com/contest/332/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  string s;
  while (cin >> n >> s) {
    int ans = 0;
    for (int i = n; i < s.length(); i += n) {
      ans += s[i - 1] == s[i - 2] && s[i - 1] == s[i - 3];
    }
    cout << ans << endl;
  }
  return 0;
}
