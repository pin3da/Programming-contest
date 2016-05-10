#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool game(string a, string b) {
  if ("tesoura" == a && "papel" == b) return 1;
  if ("papel" == a && "pedra" == b) return 1;
  if ("pedra" == a && "lagarto" == b) return 1;
  if ("lagarto" == a && "Spock" == b) return 1;
  if ("Spock" == a && "tesoura" == b) return 1;
  if ("tesoura" == a && "lagarto" == b) return 1;
  if ("lagarto" == a && "papel" == b) return 1;
  if ("papel" == a && "Spock" == b) return 1;
  if ("Spock" == a && "pedra" == b) return 1;
  if ("pedra" == a && "tesoura" == b) return 1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  string a, b;
  for (int k = 0; k < n; ++k) {
    cout << "Caso #" << (k + 1) << ": ";
    cin >> a >> b;
    if (a == b)
      cout << "De novo!" << endl;
    else if (game(a, b))
      cout << "Bazinga!" << endl;
    else
      cout << "Raj trapaceou!" << endl;

  }
  return 0;
}
