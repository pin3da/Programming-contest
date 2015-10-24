using namespace std;
#include <bits/stdc++.h>

struct pt {
  long long x, y;
  pt() {}
  pt(long long x, long long y) : x(x), y(y) {}
  pt(const pt &p) : x(p.x), y(p.y)    {}
  pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
};

long long cross(pt p, pt q)   { return p.x*q.y-p.y*q.x; }

int main() {
  int tc; cin >> tc;
  while (tc--) {
    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    pt ab = b - a;
    pt ac = c - a;
    long long bo = __gcd(llabs(a.x - b.x), llabs(a.y - b.y)) - 1;
       bo += __gcd(llabs(a.x - c.x), llabs(a.y - c.y)) - 1;
       bo += __gcd(llabs(b.x - c.x), llabs(b.y - c.y)) - 1;
       bo += 3;
    long long area = llabs(cross(ab, ac));
    long long i = (area + 2 - bo) >> 1;
    cout << i << endl;
  }
  return 0;
}
