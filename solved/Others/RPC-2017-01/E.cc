#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define debug(x) cout << #x " = " << (x) << endl

typedef double ld;

const ld EPS = 1e-10;
int cmp(ld x, ld y = 0, ld tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T>
struct _point {
  T x, y;
  _point () {}
  _point (T a, T b) : x(a), y(b) {}
  T dot(const _point &p) {
    return x * p.x + y * p.y;
  }

  T dist2(const _point &p) {
    _point d(x - p.x, y - p.y);
    return d.dot(d);
  }

  _point operator - (const _point p) const {
    return _point(x - p.x, y - p.y);
  }
  _point operator + (const _point p) const {
    return _point(x + p.x, y + p.y);
  }
  _point operator * (const T c) const {
    return _point (x * c, y * c);
  }
};

typedef _point<double> point;

const int MN = 5050;
int pi[MN];
int acc[MN];

point p[MN];

void init(int n) {
  for (int i = 0; i < n + 1; ++i) {
    acc[i] = 1;
    pi[i] = i;
  }
}

int fs(int x) {
  return pi[x] == x ? x : pi[x] = fs(pi[x]);
}

void js(int x, int y) {
  if (fs(x) == fs(y))
    return;

  acc[fs(y)] += acc[fs(x)];
  pi[fs(x)] = fs(y);
}


vector<point> find_center(point a, point b, double r) {
  point d = (a - b) * 0.5;
  if (d.dot(d) > r * r) {
    return vector<point> ();
  }
  point e = b + d;
  double fac = sqrt(r * r - d.dot(d));
  vector<point> ans;
  point x =  point(-d.y, d.x);
  double l = sqrt(x.dot(x));
  x = x * (fac / l);
  ans.push_back(e + x);
  x =  point(d.y, -d.x);
  x = x * (fac / l);
  ans.push_back(e + x);
  return ans;
}


int brute_force(vector<int> &tmp) {
  int best = 0;
  int n = tmp.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      vector<point> centers =
        find_center(p[tmp[i]], p[tmp[j]], 2);
      for (auto &c : centers) {
        int cur = 1;
        set<int> roots;
        for (int k = 0; k < n; ++k) {
          point other = p[tmp[k]];
          if (cmp(c.dist2(other), 4) != 1) {
            roots.insert(fs(tmp[k]));
          }
        }
        for (int r : roots)
          cur += acc[r];

        best = max(best, cur);
      }
    }
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  if (n == 1) {
    cout << 2 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i)
    cin >> p[i].x >> p[i].y;

  init(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (cmp(p[i].dist2(p[j]), 4) != 1) {
        js(i, j);
      }
    }
  }

  int ans = 0;

  vector<pair<double, int>> nuevo(n);
  vector<int> tmp;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, acc[fs(i)]);
    int len = 0;
    for (int j = 0; j < n; ++j) {
      if (cmp(p[i].dist2(p[j]), 16) != 1)
        nuevo[len++] = make_pair(p[i].dist2(p[j]), j);
    }
    sort(nuevo.begin(), nuevo.begin() + len);
    tmp.clear();
    for (int j = 0; j < 8 && j < len; ++j)
      tmp.emplace_back(nuevo[j].second);
    ans = max(ans, brute_force(tmp));
  }

  cout << ans << endl;

  return 0;
}
