#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x; cin >> x;
  if (!(x & 1))
    x++;
  for (int i = 0; i < 12; i += 2)
    cout << x + i << endl;
  return 0;
}
