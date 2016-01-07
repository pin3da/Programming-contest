#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {

  int i = 0, v = 0, x = 0, l = 0, c = 0;
  for (int p = 1; p <= n; ++p) {
    if (p == 100) {
      c++;
      continue;
    }
    int t = p / 10;
    if (t <= 3) {
      x += t;
    } else  if (t == 4) {
      x++;l++;
    } else if (t == 9) {
      c++;x++;
    } else {
      l++; x += t - 5;
    }
    t = p % 10;
    if (t <= 3) {
      i += t;
    } else  if (t == 4) {
      i++;v++;
    } else if (t == 9) {
      x++;i++;
    } else {
      v++; i += t - 5;
    }
  }
  cout << n << ": " << i << " i, " << v << " v, " << x << " x, " << l << " l, " << c << " c" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) solve(n);
  return 0;
}
