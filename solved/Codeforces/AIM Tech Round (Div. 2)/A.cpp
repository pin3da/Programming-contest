// http://codeforces.com/contest/624/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  long double d, l, a, b;
  cin >> d >> l >> a >> b;

  l -= d;
  cout << setprecision(10) << max<long double>(0.0, l / (a + b)) << endl;
  return 0;
}
