#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long powers[40];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (int  i = 0; i < 40; ++i)
    powers[i] = 1LL << i;

  int n;
  while (cin >> n && n) {
    int u = 0, r = 0, i = 0;
    int a, b, c;
    int x, y, z;
    while (n--) {
      cin >> a >> b >> c;
      x = y = z = 0;
      for (int j = 0; j < 40; ++j) {
        if (powers[j] == a)
          u++, x = 1;
        if (powers[j] == b)
          r++, y = 1;
        if (powers[j] == c)
          i++, z = 1;
      }
      if (a >= max(b, c) && x)
        u++;
      if (b >= max(a, c) && y)
        r++;
      if (c >= max(a, b) && z)
        i++;
    }
    // D(u);D(r);D(i);
    if (u == max(r, i) ||
        r == max(u, i) ||
        i == max(r, u)) {
      cout << "URI" << endl;
      continue;
    }

    if (u > max(r, i))
      cout << "Uilton" << endl;
    if (r > max(u, i))
      cout << "Rita" << endl;
    if (i > max(u, r))
      cout << "Ingred" << endl;

  }
  return 0;
}

