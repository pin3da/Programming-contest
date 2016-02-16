#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a;
  while (cin >> a) {
    if (a == 61)
      cout << "Brasilia" << endl;
    else if (a == 71)
      cout << "Salvador" << endl;
    else if (a == 11)
      cout << "Sao Paulo" << endl;
    else if (a == 21)
      cout << "Rio de Janeiro" << endl;
    else if (a == 32)
      cout << "Juiz de Fora" << endl;
    else if (a == 19)
      cout << "Campinas" << endl;
    else if (a == 27)
      cout << "Vitoria" << endl;
    else if (a == 31)
      cout << "Belo Horizonte" << endl;
    else
      cout << "DDD nao cadastrado" << endl;
  }
  return 0;
}
