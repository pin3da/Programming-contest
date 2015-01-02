using namespace std;
#include <bits/stdc++.h>

int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (a != 0 and b != 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

struct Fraction {
  int p, q;
  Fraction(int P, int Q) : p(P), q(Q) { simplify(); }
  Fraction(int P) : p(P), q(1) {}
  Fraction() {}
  void simplify() {
    int g = gcd(p, q);
    p /= g;
    q /= g;
  }
  Fraction operator+(const Fraction &f) const {
    return Fraction(p * f.q + q * f.p, q * f.q);
  }
  Fraction operator-(const Fraction &f) const {
    return Fraction(p * f.q - q * f.p, q * f.q);
  }
  Fraction operator*(const Fraction &f) const {
    return Fraction(p * f.p, q * f.q);
  }
  Fraction operator/(const Fraction &f) const {
    return Fraction(p * f.q, q * f.p);
  }
  Fraction operator*(int n) const {
    return Fraction(p * n, q);
  }
  Fraction operator%(int m) const {
    return Fraction(p % (m*q), q);
  }
  bool operator<(const Fraction &f) const { return p*f.q < f.p*q; }
  bool operator==(int n) const { return p == n*q; }
  bool operator<=(int n) const { return p <= n*q; }
  bool operator>=(int n) const { return p >= n*q; }
};

int read() {
  int a, b, c;
  char d;
  cin >> a >> d >> b >> d >> c;
  return a * 3600 + b * 60 + c;
}

void mprint(const Fraction &f) {
  int sec = f.p / f.q;
  printf("%02d:%02d:%02d", sec / 3600, (sec / 60) % 60, sec % 60);
  if (f.p % f.q) {
    printf(" %d/%d", f.p - sec * f.q, f.q);
  }
  puts("");
}

void solve() {
  int sym = read();
  int from = read();
  int to = read();

  Fraction hour(360, 12 * 60 * 60);
  Fraction minu(360, 60 * 60);
  vector<Fraction> ans;
  Fraction axis = hour * sym;
  for (int i = 0; i < 13; ++i) {
    Fraction current = hour * i * 3600;
    // Fraction tmp = ((axis * 2 - current) / minu);
    // xseg * hours = (tmp - xseg) * minus
    // x = ((tmp * minu) / (hour + minu) );
    Fraction x = ((axis * 2 - current) / (hour + minu) );
    x = x + Fraction(i * 3600);
    if (x >= 43200)
      x = x - Fraction(43200);

    if (x >= from and x <= to)
      ans.push_back(x);
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    mprint(ans[i]);
  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
