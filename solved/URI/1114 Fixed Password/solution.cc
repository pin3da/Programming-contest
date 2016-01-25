#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  while (cin >> x) {
    cout << ((x == 2002)? "Acesso Permitido" : "Senha Invalida") << endl;
    if (x == 2002) break;
  }
  return 0;
}
