#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    a = a * 60 + b;
    c = c * 60 + d;
    if (c <= a) c += 24 * 60;
    a = c - a;
    cout << "O JOGO DUROU " << a / 60 << " HORA(S) E " << a % 60 << " MINUTO(S)" << endl;
  }
  return 0;
}
