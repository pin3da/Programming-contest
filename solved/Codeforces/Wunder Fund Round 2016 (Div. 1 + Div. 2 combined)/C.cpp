// http://codeforces.com/contest/618/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = "  << (x) << endl
#define endl '\n'

using namespace std;

struct frac{
  long long x, y;
  frac(long long a, long long b) {
    long long g = __gcd(a, b);
    x = a / g;
    y = b / g;
  }
  bool operator < (const frac &o) const {
    return (x * o.y < y * o.x);
  }
};

struct point{
  long long x, y;
  int id;
  point() {}
  point(long long X, long long Y) : x(X), y(Y) {}
  bool operator <(const point &o) const {
    if (y == o.y)
      return x < o.x;
    return y < o.y;
  }
};

long long cross(const point &a, const point &b, const point &c){
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void solve(vector<point> &p){
  map<frac, vector<point>> a;
  for (auto &i : p)
    a[frac(i.y, i.x)].push_back(i);

  int seen = 3;
  vector<point> cool;
  cool.reserve(p.size());
  for (auto &i : a) {
    sort(i.second.begin(), i.second.end());
    vector<point> &b = i.second;
    for (auto &j : b)
      cool.push_back(j);
  }

  for (int i = 0; i + 2 < cool.size(); ++i) {
    if (cross(cool[i], cool[i + 1], cool[i + 2]) != 0) {
      cout << cool[i].id << " " << cool[i + 1].id << " " << cool[i + 2].id << endl;
      return;
    }
  }


  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<point> p(n);
  int j = 1;
  for (auto &i : p) {
    cin >> i.x >> i.y;
    i.x += 1000000001;
    i.y += 1000000001;
    i.id = j;
    j++;
  }
  solve(p);

  return 0;
}
