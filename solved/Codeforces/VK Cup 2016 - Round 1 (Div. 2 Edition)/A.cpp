// http://codeforces.com/contest/658/problem/A

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, c;
  while (cin >> n >> c) {
    vector<int> p(n), t(n);
    for (auto &i : p) cin >> i;
    for (auto &i : t) cin >> i;
    int ta = 0, tb = 0;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      ta += t[i];
      tb += t[n - i - 1];
      a += max(0, p[i] - c * ta);
      b += max(0, p[n - i - 1] - c * tb);
    }

    if (a > b) {
      cout << "Limak" << endl;
    } else if (b > a) {
      cout << "Radewoosh" << endl;
    } else {
      cout << "Tie" << endl;
    }
  }

  return 0;
}
