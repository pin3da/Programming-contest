#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c;
  while (cin >> a >> b >> c) {
    if ((a + b + c) == 1 || (a + b + c) == 2) {
      if (a == b)
        cout << 'C' << endl;
      if (b == c)
        cout << 'A' << endl;
      if (a == c)
        cout << 'B' << endl;
    } else {
      cout << '*' << endl;
    }
  }

  return 0;
}
