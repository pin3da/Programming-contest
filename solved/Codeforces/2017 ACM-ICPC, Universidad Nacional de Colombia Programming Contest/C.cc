#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef long long T;
struct point {
  T x, y, z;
  point() {}
  point(T a, T b, T c) : x(a), y(b), z(c) {}
};

point sub(point &a, point &b) {
  return point(a.x - b.x, a.y - b.y, a.z - b.z);
}

long long dot(point &a, point &b) {
  long long x = a.x * b.x;
  long long y = a.y * b.y;
  long long z = a.z * b.z;
  return x + y + z;
}

point cross(point &a, point &b) {
  return point(
      a.y * b.z - a.z * b.y,
      -a.x * b.z + a.z * b.x,
      a.x * b.y - a.y * b.x
  );
}

long long norm(point a) {
  return dot(a, a);
}

int fs(vector<int> &p, int x) {
  return x == p[x] ? x : p[x] = fs(p, p[x]);
}

void js(vector<int> &p, int x, int y) {
  p[fs(p, x)] = fs(p, y);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;

  point pivot;
  cin >> pivot.x >> pivot.y >> pivot.z;

  vector<point> all(n - 1);
  vector<int> p(n - 1);

  for (int i = 0; i < n - 1; i++)
    p[i] = i;

  for (auto &i : all)
    cin >> i.x >> i.y >> i.z;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < i; j++) {
      point a = sub(all[i], pivot);
      point b = sub(all[j], pivot);
      long long c = norm(cross(a, b));
      if (c == 0) {
        js(p, i, j);
      }
    }
  }

  set<int> roots;
  for (int i = 0; i < n - 1; i++)
    roots.insert(fs(p, i));

  cout << roots.size() << endl;
  return 0;
}
