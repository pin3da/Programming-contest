#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
};

double dist(PT p, PT q) {
  double x = p.x - q.x,
         y = p.y - q.y;
  return sqrt(x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  PT a, b, r;
  cout << fixed << setprecision(14);
  while (cin >> a.x >> a.y >> b.x >> b.y >> r.x >> r.y) {
    int n; cin >> n;
    vector<PT> p(n);
    vector<double> d(n);
    vector<pair<double, int>> ba(n), bb(n);
    double total = 0;
    int j = 0;
    for (auto &i : p) {
      cin >> i.x >> i.y;
      d[j] = dist(i, r);
      ba[j].first = -d[j] + dist(i, a);
      bb[j].first = -d[j] + dist(i, b);
      ba[j].second = j;
      bb[j].second = j;
      total += 2.0 * d[j];
      j++;
    }

    sort(ba.begin(), ba.end());
    sort(bb.begin(), bb.end());
    double best = total;
    if (ba[0].second != bb[0].second)
      best += ba[0].first + bb[0].first;
    else
      best += min(ba[0].first + bb[1].first, ba[1].first + bb[0].first);
    best = min(best, min(total + ba[0].first, total + bb[0].first));
    cout << best << endl;
  }
  return 0;
}
