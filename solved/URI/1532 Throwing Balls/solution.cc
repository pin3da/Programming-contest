#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1111;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, v;
  while (cin >> n >> v && (n + v)) {
    int ok = false;
    for (int i = 1; i <= v && !ok; ++i) {
      int pos = 0, step = i;
      while (pos < n && !ok && step > 0) {
        if (((n - pos) % step == 0) && ((n - pos) / step) <= step)
          ok = true;
        pos += step * step;
        step--;
      }
    }
    if (ok)
      cout << "possivel" << endl;
    else
      cout << "impossivel" << endl;
  }
  return 0;
}
