#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long r(int x, int y) {
  return 9 * x * x + y * y;
}

long long b(int x, int y) {
  return 2 * x * x + 25 * y * y;
}

long long c(int x, int y) {
  return -100 * x + y * y * y;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int x, y; cin >> x >> y;
    if (r(x, y) > b(x, y) && r(x, y) > c(x, y))
      cout << "Rafael ganhou" << endl;
    if (r(x, y) < b(x, y) && b(x, y) > c(x, y))
      cout << "Beto ganhou" << endl;
    if (c(x, y) > b(x, y) && r(x, y) < c(x, y))
      cout << "Carlos ganhou" << endl;
  }
  return 0;
}
