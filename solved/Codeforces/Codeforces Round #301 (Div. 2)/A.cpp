// http://codeforces.com/contest/540/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() { ___
  int n;
  cin >> n;
  string a; string b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    ans += min(fabs(x - y), 10 - fabs(x - y));
  }

  cout << ans << endl;
  return 0;
}
