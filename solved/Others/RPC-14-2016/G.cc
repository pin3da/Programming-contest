#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl

#define endl '\n'
typedef long double ld;

struct point {
  ld x, y;
  point() {}
  point(ld a, ld b) : x(a), y(b) {}
  
  ld norm() {
    return sqrt(x * x + y * y);
  }
  point operator -( const point &p) const {
    return point(x - p.x, y - p.y);
  }
};

int main() {
  point a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  ld r; cin >> r;
  
  ld x = (a - b).norm();
  ld y = (c - b).norm();
  ld z = (c - a).norm();
  
  ld A1 = r * (x + y + z)  * 0.5; 
  ld t = x * x + y * y - z * z;
  ld A2 = 0.25 * sqrt(4.0 * x * x * y * y - t * t);
  
  ld dif = A2 - A1;
  ld ans = dif / A1;
  cout << fixed << setprecision(5);
  cout << ans * 100.0 << endl;
  return 0;
}
