#include<bits/stdc++.h>
using namespace std;

struct tr{
  double a, b, c;
};

void solve() {
  int n;
  cin >> n;
  vector<tr> a(n);
  double best = -1.0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    double r = (a[i].b / a[i].a ) * 0.5;
    double f = -a[i].a * r * r + a[i].b * r + a[i].c;
    if (f > best) {
      best = f;
      ans = i + 1;
    }
  }
  cout << ans << endl;
}

int main() {
 int tc; cin >> tc;
 for (int i = 0; i < tc; ++i) {
  solve();
 }
 return 0;
}
