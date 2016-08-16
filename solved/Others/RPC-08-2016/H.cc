#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double T;

const T eps = 1e-10;

int cmp(T x, T y) {
  return (x <= y + eps) ? (x + eps < y) ? -1 : 0 : 1;
}

struct vec {
  T x, y;
  vec() {}
  vec(T a, T b) : x(a), y(b) {}
  vec operator - (const vec &o) const {
    return vec(x - o.x, y - o.y);
  }
  T cross(const vec &o) const {
    return x * o.y - y * o.x;
  }
  bool operator < (const vec &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
  bool operator == (const vec &o) const {
    return x == o.x && y == o.y;
  }
};

typedef vec point;
typedef vector<point> poly;


bool collinear(point a, point b, point c) {
  vec A = b - a, B = c - a;
  return cmp(A.cross(B), 0) == 0;
}

bool segments_intersect(point &a, point &b, point &c, point &d) {
  vec A = c - a, B = d - a;
  vec D = a - c, E = b - c;
  vec AB = b - a, CD = d - c;
  if (A.cross(AB) * B.cross(AB) < 0 && D.cross(CD) * E.cross(CD) < 0)
    return true;
  return false;
}

bool poly_intersect(poly &a, poly &b) {
  for (int i = 0; i < a.size(); ++i) {
    int j = (i + 1) % a.size();
    for (int k = 0; k < b.size(); ++k) {
      int k2 = (k + 1) % b.size();
      if (segments_intersect(a[i], a[j], b[k], b[k2]))
        return true;
    }
  }
  return false;
}

bool line_cut(poly ped, point a, point b) {
  for (int i = 0; i < ped.size(); ++i) {
    int j = (i + 1) % ped.size();
    if (segments_intersect(ped[i], ped[j], a, b)) return true;
  }
  return false;
}

void print(poly &p) {
  for (int i = 0; i < p.size(); ++i)
    cout << p[i].x << " " << p[i].y << endl;
  cout << endl;
}

const int MN = 444;

int cut[MN][MN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int w, l; cin >> w >> l;
    T x, y, z; cin >> x >> y >> z;
    poly ped;
    ped.push_back(point(x, y));
    ped.push_back(point(x + z, y));
    ped.push_back(point(x + z, y + z));
    ped.push_back(point(x, y + z));

    vector<point> all;
    for (int i = 0; i <= w; ++i) {
      all.push_back(point(i, 0));
      all.push_back(point(i, l));
    }
    for (int j = 0; j <= l; ++j) {
      all.push_back(point(0, j));
      all.push_back(point(w, j));
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    memset(cut, 0, sizeof cut);

    for (int i = 0; i < all.size(); ++i) {
      for (int j = i + 1; j < all.size(); ++j) {
        cut[i][j] = cut[j][i] = line_cut(ped, all[i], all[j]);
      }
    }

    int ans = 0;
    for (int i = 0; i < all.size(); ++i) {
      for (int j = i + 1; j < all.size(); ++j) {
        if (cut[i][j]) continue;
        for (int k = j + 1; k < all.size(); ++k) {
          if (!collinear(all[i], all[j], all[k])) {
            if (!(cut[i][j] || cut[i][k] || cut[j][k])) {
              ans++;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
