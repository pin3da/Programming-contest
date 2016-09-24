#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double T;
struct PT {
  T x, y;
  PT() {}
  PT(T x, T y) : x(x), y(y) {}
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  bool operator < (const PT &p) const {
    if (x== p.x) return y < p.y;
    return x < p.x;
  }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
T dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
T dist2(PT p, PT q)   { return dot(p-q,p-q); }
T mdist(PT p, PT q)   { return sqrt(dist2(p, q));}


int n, E, S;

T func(vector<PT> &c, vector<PT> &all) {
  long double lenc = 0;
  for (int i = 0; i < c.size(); ++i) {
    int j = (i + 1) % c.size();
    lenc += mdist(c[i], c[j]);
  }

  long double ans = 1e100;
  for (int i = 0; i < c.size(); ++i) {
    int j = (i + 1) % c.size();
    long double tmp = lenc + mdist(all[E], c[i]) + mdist(all[S], c[j]) - mdist(c[i], c[j]);
    ans = min(ans, tmp);
    j = (i - 1 + c.size()) % c.size();
    tmp = lenc + mdist(all[E], c[i]) + mdist(all[S], c[j]) - mdist(c[i], c[j]);
    ans = min(ans, tmp);
  }
  return ans;
}

bool cmp_y(const PT &a, const PT &b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

void solve() {
  E--;S--;
  vector<PT> all(n);
  vector<PT> a, b, c;
  a.reserve(n);
  b.reserve(n);
  c.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> all[i].x >> all[i].y;
    if (i != E && i != S) c.push_back(all[i]);
  }
  if (n == 2) {
    cout << mdist(all[0], all[1]) << endl;
    return;
  }

  long double ans = 1e100;
  for (int i = (E + 1) % n; i != S; i = (i + 1) % n)
    a.push_back(all[i]);

  for (int i = (S + 1) % n; i != E; i = (i + 1) % n)
    b.push_back(all[i]);

  if (a.size() > 0 && b.size() > 0) {
    long double lena = 0, lenb = 0;
    for (int i = 0; i + 1 < a.size(); ++i)
      lena += mdist(a[i], a[i + 1]);
    for (int i = 0; i + 1 < b.size(); ++i)
      lenb += mdist(b[i], b[i + 1]);

    long double op1 = lena + lenb + mdist(all[E], a[0]) + mdist(a.back(), b[0]) + mdist(b.back(), all[S]);
    long double op2 = lena + lenb + mdist(all[E], a[0]) + mdist(a.back(), b.back()) + mdist(b[0], all[S]);
    long double op3 = lena + lenb + mdist(all[E], a.back()) + mdist(a[0], b[0]) + mdist(b.back(), all[S]);
    long double op4 = lena + lenb + mdist(all[E], a.back()) + mdist(a[0], b.back()) + mdist(b[0], all[S]);
    ans = min(ans, min(min(op1, op2), op3));
    ans = min(ans, op4);

    swap(a, b);
    op1 = lena + lenb + mdist(all[E], a[0]) + mdist(a.back(), b[0]) + mdist(b.back(), all[S]);
    op2 = lena + lenb + mdist(all[E], a[0]) + mdist(a.back(), b.back()) + mdist(b[0], all[S]);
    op3 = lena + lenb + mdist(all[E], a.back()) + mdist(a[0], b[0]) + mdist(b.back(), all[S]);
    op4 = lena + lenb + mdist(all[E], a.back()) + mdist(a[0], b.back()) + mdist(b[0], all[S]);
    ans = min(ans, min(min(op1, op2), op3));
    ans = min(ans, op4);
  }

  ans = min(ans, func(c, all));
  sort(c.begin(), c.end());
  ans = min(ans, func(c, all));
  sort(c.begin(), c.end(), cmp_y);
  ans = min(ans, func(c, all));

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(6);
  while (cin >> n >> E >> S)
    solve();
  return 0;
}
