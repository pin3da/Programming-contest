#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool play(string a, string b) {
  if (a == "ataque")
    return true;
  if (a == "pedra" && b == "papel")
    return true;
  return false;
}

void solve() {
  string a, b;
  cin >> a >> b;
  if (a == "ataque" && b == "ataque") {
    cout << "Aniquilacao mutua" << endl;
  } else if (a == "pedra" && b == "pedra") {
    cout << "Sem ganhador" << endl;
  } else if (a == "papel" && b == "papel") {
    cout << "Ambos venceram" << endl;
  } else {
    if (play(a, b))
      cout << "Jogador 1 venceu" << endl;
    else
      cout << "Jogador 2 venceu" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--)
    solve();

  return 0;
}

