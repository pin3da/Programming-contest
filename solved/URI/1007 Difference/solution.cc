#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d)
    cout << "DIFERENCA = " << (a * b - c * d) << endl;
  return 0;
}
