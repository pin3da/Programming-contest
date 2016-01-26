#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= y; ++i) {
    if ((i - 1) % x) cout << " ";
    cout << i;
    if ((i % x) == 0) cout << endl;
  }
  return 0;
}
