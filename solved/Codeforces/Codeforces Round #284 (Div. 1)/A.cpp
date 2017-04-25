// http://codeforces.com/contest/498/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
struct point {
  double x, y;
};


int main() {
  point a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int n;
  cin >> n;
  int x, y, z;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    double f = a.x * x + a.y * y + z;
    double s = b.x * x + b.y * y + z;
    if (f * s < 0)
      ans++;
  }
  cout << ans << endl;


  return 0;
}
