// http://codeforces.com/contest/732/problem/A

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << (x) << endl

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  long long k, r;
  while (cin >> k >> r) {
    for (long long i = 1; i < 1000001; ++i) {
      if (((k * i) % 10 == r) || ((k * i) % 10 == 0)) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
