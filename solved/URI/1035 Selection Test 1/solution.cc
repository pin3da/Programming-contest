#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    if (b > c && d > a && (c + d) > (a + b) && (c > 0) && d > 0 && (a & 1) == 0)
      cout << "Valores aceitos" << endl;
    else
      cout << "Valores nao aceitos" << endl;
  }

  return 0;
}
