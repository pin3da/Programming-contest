#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, z;
  cin >> x;
  while (cin >> z && z <= x);

  int accum = 0, i;
  for (i = 0; accum <= z; ++i) {
    accum += x;
    x++;
  }
  cout << i << endl;
  return 0;
}
