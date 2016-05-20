#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long long T;

struct point {
  T x, y;
  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  bool operator == (const point &o) const {
    return x == o.x && y == o.y;
  }
};

T cross(const point &O, const point &A, const point &B){
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<point> convex_hull(vector<point> P){
  int n = P.size(), k = 0;
  vector<point> H(2 * n);
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  H.resize(k);
  return H;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<point> p(n);
    for (auto &i : p) cin >> i.x >> i.y;
    int ans = 0;
    while (p.size()) {
      vector<point> ch = convex_hull(p);
      ans++;
      set<point> seen;
      for (auto &i : ch) seen.insert(i);
      vector<point> pp;
      for (auto &i : p) if (!seen.count(i))
        pp.push_back(i);
      p = pp;
    }
    if (ans & 1)
      cout << "Take this onion to the lab!" << endl;
    else
      cout << "Do not take this onion to the lab!" << endl;
  }
  return 0;
}
