#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

template<class T>
struct point {
  T x, y;
  point (T a, T b) : x(a), y(b) {}
  T dot(const point &p) {
    return x * p.x + y * p.y;
  }

  T dist2(const point &p) {
    point d(x - p.x, y - p.y);
    return d.dot(d);
  }

  point operator - (const point p) const {
    return point(x - p.x, y - p.y);
  }
  point operator + (const point p) const {
    return point(x + p.x, y + p.y);
  }
  point operator * (const T c) const {
    return point (x * c, y * c);
  }
};

typedef point<long double> mp;
const long double eps = 1e-10;


vector<mp> find_center(mp a, mp b, long double r) {
  mp d = (a - b) * 0.5;
  if (d.dot(d) > r * r) {
    return vector<mp> ();
  }
  mp e = b + d;
  long double fac = sqrt(r * r - d.dot(d));
  vector<mp> ans;
  mp x =  mp(-d.y, d.x);
  long double l = sqrt(x.dot(x));
  x = x * (fac / l);
  ans.push_back(e + x);
  x =  mp(d.y, -d.x);
  x = x * (fac / l);
  ans.push_back(e + x);
  return ans;
}

void printp(mp p) {
  cout << p.x << ' ' << p.y << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  vector<mp> all;
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    double x, y;
    ss >> x >> y;
    all.push_back(mp(x, y));
  }

  int n = all.size();

  int best = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      vector<mp> center = find_center(all[i], all[j], 2.5);
      for (int x = 0; x < (int) center.size(); ++x) {
        int cur = 0;
        for (int k = 0; k < n; ++k) {
          if (center[x].dist2(all[k]) - eps < (2.5 * 2.5))
            cur++;
        }
        best = max(best, cur);
      }
    }
  }
  cout << best << endl;
  return 0;
}
