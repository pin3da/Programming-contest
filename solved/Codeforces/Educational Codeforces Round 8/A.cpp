// http://codeforces.com/contest/628/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, b, p;
  while (cin >> n >> b >> p) {
    int t = n;
    int x = 0;
    while (t > 1) {
      int k = 1 << (int)floor(log2(t));
      x += k * b + (k >> 1);
      t -= k;
      t += (k >> 1);
    }
    cout << x << " " << n * p << endl;
  }
  return 0;
}
