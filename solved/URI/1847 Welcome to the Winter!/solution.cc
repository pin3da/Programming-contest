#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c;
  while (cin >> a >> b >> c) {
    int m1 = b - a,
        m2 = c - b;

    if (m2 > m1)
      cout << ":)"  << endl;
    else if (m2 < m1)
      cout << ":(" << endl;
    else {
      if (m1 <= 0)
        cout << ":(" << endl;
      else
        cout << ":)" << endl;
    }
  }
  return 0;
}
