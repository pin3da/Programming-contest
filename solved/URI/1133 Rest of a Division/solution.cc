#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x, y;
  cin >> x >> y;
  if (y < x)
    swap(x, y);

  for (int i = x + 1; i < y; ++i) {
    if ((i % 5) & 2)
      cout << i << endl;
  }
  return 0;
}
