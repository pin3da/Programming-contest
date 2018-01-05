#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long a, b;
  cin >> a >> b;
  long long x, y, z;
  cin >> x >> y >> z;

  long long yellow = x * 2 + 1 * y;
  long long blue = y + 3 * z;

  cout << max(0LL, yellow - a) + max(0LL, blue - b) << endl;
  return 0;
}
