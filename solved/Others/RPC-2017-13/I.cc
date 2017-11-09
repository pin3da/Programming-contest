#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct point {
  int x, y;
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  long long n, x, y;

  while (cin >> n) {
    vector<point> points(n);
    map<long long, long long> qua;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      qua[x + y]++;
      qua[x - y]++;
    }
    long long good = 0;
    for (auto &i : qua) {

      good += i.second * (i.second - 1);
    }
    cout << fixed << setprecision(10) << (double)good / (n * n) << endl;
  }
  return 0;
}
