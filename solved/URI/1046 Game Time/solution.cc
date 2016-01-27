#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout << "O JOGO DUROU ";
  if (b > a)
    cout << b - a;
  else if (a > b)
    cout << 24 - a + b;
  else
    cout << 24;
  cout << " HORA(S)" << endl;

  return 0;
}
