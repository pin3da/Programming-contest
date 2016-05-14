#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long d(int a, int b, int c, int d) {
  long long x = a - c,
            y = b - d;
  return x * x + y * y;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int c; cin >> c;
  while (c--) {
    int n, a, b;
    cin >> n >> a >> b;
    long long best = 1LL << 50;
    int id_best, x, y;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      if (d(a, b, x, y) < best) {
        best = d(a, b, x, y);
        id_best = i;
      }
    }
    cout << id_best + 1 << endl;
  }
  return 0;
}
