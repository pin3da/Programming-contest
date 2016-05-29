#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long fac[20];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fac[0] = fac[1] = 1;
  for (int i = 2; i < 20; ++i)
    fac[i] = fac[i - 1] * i;
  string line;
  while (cin >> line && line != "0")
    cout << fac[line.size()] << endl;
  return 0;
}
