#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef long double T;

T INF = 1e100;
T EPS = 1e-7;

struct PT {
  T x, y;
  PT() {}
  PT(T x, T y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (T c)     const { return PT(x*c,   y*c  ); }
  PT operator / (T c)     const { return PT(x/c,   y/c  ); }
};

T dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
T dist2(PT p, PT q)   { return dot(p-q,p-q); }
T cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  return os << "(" << p.x << "," << p.y << ")";
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, T r) {
  vector<PT> ret;
  b = b-a;
  a = a-c;
  T A = dot(b, b);
  T B = dot(a, b);
  T C = dot(a, a) - r*r;
  T D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}

void solve() {
  T R;
  PT center;
  read(R, center.x, center.y);
  PT laptop;
  read(laptop.x, laptop.y);

  cout << fixed << setprecision(8);

  if (center.x == laptop.x && center.y == laptop.y) {
    PT otro = center;
    center.x += R;

    T r = R * 0.5;

    PT ans = (otro - center) * 0.5 + center;

    cout << ans.x << " " << ans.y << " " << r << endl;
    return;
  }

  if (dist2(laptop, center) >= R * R + EPS) {
    cout << center.x << " " << center.y << " " << R << endl;
  } else {
    vector<PT> tmp = CircleLineIntersection(center, laptop, center, R);

    assert(tmp.size());

    T d = -1;
    PT ans = center;
    for (auto it : tmp) {
      if (dist2(it, laptop) > d) {
        ans = it;
        d = dist2(it, laptop);
      }
    }

    T r = sqrt(dist2(ans, laptop)) * 0.5;
    ans = (ans - laptop) * 0.5 + laptop;
    assert(dist2(ans, center) <= R * R);
    cout << ans.x  << " " << ans.y << " " << r - 1e-9 << endl;
  }

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

