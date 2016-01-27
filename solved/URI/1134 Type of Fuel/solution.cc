#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> t(3);
  int x;
  while (cin >>  x && x != 4) {
    if (x < 1 || x > 3) continue;
    t[x - 1]++;
  }
  cout << "MUITO OBRIGADO" << endl;
  cout << "Alcool: " << t[0] << endl;
  cout << "Gasolina: " << t[1] << endl;
  cout << "Diesel: " << t[2] << endl;
  return 0;
}
