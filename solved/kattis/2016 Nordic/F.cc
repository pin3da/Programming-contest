#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, p;
  while (cin >> n >> p) {
    long double cur = (double)p / (n + 1);
    cout << cur << endl;
  }
  return 0;
}
