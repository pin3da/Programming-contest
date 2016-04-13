#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct match {
  long long s, r;
  match () {}
  bool operator < (const match &o ) const {
    return (s - r) > (o.s - o.r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, g;
  while (cin >> n >> g) {
    vector<match> a(n);
    for (auto &i : a)
      cin >> i.s >> i.r;

    sort(a.begin(), a.end());
    int points = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i].s > a[i].r) {
        points += 3;
        continue;
      }

      if (a[i].s == a[i].r) {
        if (g) {
          g--;
          points += 3;
        } else {
          points++;
        }
      } else {
        if (g >= (a[i].r - a[i].s + 1)) {
          g -= (a[i].r - a[i].s + 1);
          points += 3;
        } else if (g == (a[i].r - a[i].s)) {
          g = 0;
          points++;
        }
      }
    }

    cout << points << endl;
  }
  return 0;
}
