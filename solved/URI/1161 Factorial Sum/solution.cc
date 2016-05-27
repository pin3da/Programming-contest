#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 21;
long long fac[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fac[0] = fac[1] = 1;
  for (int i = 2; i < MN; ++i)
    fac[i] = fac[i - 1] * i;
  int a, b;
  while (cin >> a >> b)
    cout << fac[a] + fac[b] << endl;
  return 0;
}
