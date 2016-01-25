#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x, y;
  cin >> x >> y;
  cout << (((x % y == 0) || (y % x == 0)) ? "Sao Multiplos" : "Nao sao Multiplos") << endl;
  return 0;
}
