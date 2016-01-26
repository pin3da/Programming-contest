#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x, y;
  while (cin >> x >> y && x * y != 0)
    if (x * y > 0)
      if (x > 0)
        cout << "primeiro" << endl;
      else
        cout << "terceiro" << endl;
    else
      if (x < 0)
        cout << "segundo" << endl;
      else
        cout << "quarto" << endl;
  return 0;
}
