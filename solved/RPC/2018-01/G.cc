#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif

struct point {
  int x, y, z;

  void read() {
    cin >> x >> y >> z;
  }

  bool operator != (const point &o) const {
    return x != o.x || y != o.y || z != o.z;
  }

  bool operator == (const point &o) const {
    return (x == o.x && y == o.y && z == o.z);
  }
};

point next(point a, point &b) {
  if (a.x != b.x) {
    a.x += b.x - a.x > 0 ? 1 : -1;
  } else if (a.y != b.y) {
    a.y += b.y - a.y > 0 ? 1 : -1;
  } else if (a.z != b.z) {
    a.z += b.z - a.z > 0 ? 1 : -1;
  }
  return a;
}

/*
auto &operator<<(auto &s, point p) {
  s << "(" << p.x << ", " << p.y << ", " << p.z << ")";
  return s;
}
*/


int rint() {
  if (random() & 1) return -1;
  return 1;
}

point rand_step(point a) {
  int t = random() % 3;
  if (t == 0)
    a.x += rint();
  if (t == 1)
    a.y += rint();
  if (t == 2)
    a.z += rint();
  return a;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));

  point sa, ea, sb, eb;
  sa.read(); ea.read(); sb.read(); eb.read();

  vector<point> delta_a, delta_b;

  delta_a.push_back(sa);
  delta_b.push_back(sb);

  while (sa != ea || sb != eb) {
    point next_a = next(sa, ea), next_b = next(sb, eb);
    while ((next_a == next_b) || ((next_a == sb) && (next_b == sa))) {
      if (random() & 1) {
        next_a = rand_step(sa);
      } else {
        next_b = rand_step(sb);
      }
    }
    delta_a.push_back(next_a);
    delta_b.push_back(next_b);
    sa = next_a;
    sb = next_b;
  }

  assert(sa == ea);
  assert(sb == eb);
  assert(int(delta_a.size()) <= 7000);

  for (int i = 0; i < (int)delta_a.size(); i++) {
    cout << "(" << delta_a[i].x << " " << delta_a[i].y << " " << delta_a[i].z << ") ";
    cout << "(" << delta_b[i].x << " " << delta_b[i].y << " " << delta_b[i].z << ")\n";
  }

  return 0;
}
