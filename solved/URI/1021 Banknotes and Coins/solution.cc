#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long notas[] = {10000, 5000, 2000, 1000, 500, 200};
long long moedas[] = {100, 50, 25, 10, 5, 1};

long double no[] = {100, 50, 20, 10, 5, 2};
long double mo[] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a;
  long double _a;
  cout << fixed << setprecision(2);
  while (cin >> _a) {
    a = round(_a * 100);
    cout << "NOTAS:" << endl;
    for (int i = 0; i < 6; ++i) {
      long long frec = a / notas[i];
      cout << frec << " nota(s) de R$ " << no[i] << endl;
      a %= notas[i];
    }
    cout << "MOEDAS:" << endl;
    for (int i = 0; i < 6; ++i) {
      long long frec = a / moedas[i];
      cout << frec << " moeda(s) de R$ " << mo[i] << endl;
      a %= moedas[i];
    }
  }
  return 0;
}
