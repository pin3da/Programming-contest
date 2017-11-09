#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;
  while (cin >> n) {
    char c; cin >> c;
    if (c == 'R')
      cout << n << endl;
    if (c == 'N')
      if (n > 2)
        cout << 2 << endl;
      else
        cout << 1 << endl;
    if (c == 'K')
      if (n > 1)
        cout << 4 << endl;
      else
        cout << 1 << endl;
    if (c == 'B')
      cout << n << endl;
  }
  return 0;
}
