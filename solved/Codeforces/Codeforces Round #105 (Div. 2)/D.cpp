// http://codeforces.com/contest/148/problem/D

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double T;

const int MN = 1111;
int seen[MN][MN];
T dp[MN][MN];
T go(int a, int b) {
  if (a == 0) return 0;
  if (b <= 0) return 1;

  if (seen[a][b])
    return dp[a][b];

  seen[a][b] = true;
  T pw = a / T(a + b);
  T ans =  pw;
  T pc = (1.0 - pw) * T(b - 1) / T(a + b - 1);
  T na = a, nb = b - 2;
  T pa = (na + nb <= 0) ? 0 : na / (na + nb);
  T pb = (na + nb <= 0) ? 0 : nb / (na + nb);
  if (a + b - 1 > 0 && na + nb > 0)
    ans += pc * pa * go(a - 1, b - 2) + pc * pb * go(a, b - 3);
  return dp[a][b] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  cout << fixed << setprecision(12);
  memset(seen, 0, sizeof seen);
  while (cin >> a >> b) {
    cout << go(a, b) << endl;
  }

  return 0;
}
