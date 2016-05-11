#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
template<typename T>
struct Fraction {
  T p, q;

  Fraction() : p(0), q(1) {}
  Fraction(T P) : p(P), q(1) {}
  Fraction(T P, T Q) : p(P), q(Q) { simplify(); }
  void simplify() {
    T g = __gcd(p, q);
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
  Fraction operator%(int m) const {
    return Fraction(p % (m*q), q);
  }
  Fraction operator-() const { return Fraction(-p, q); }
  bool operator<(const Fraction &f) const { return p*f.q < q*f.p; }
  bool operator>(const Fraction &f) const { return p*f.q > q*f.p; }
  bool operator<=(const Fraction &f) const { return p*f.q <= q*f.p; }
  bool operator>=(const Fraction &f) const { return p*f.q >= q*f.p; }
  bool operator==(const Fraction &f) const { return p == f.p && q == f.q; }
};

typedef Fraction<int> fraction;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<char, fraction> s;
  s['W'] = fraction(1, 1);
  s['H'] = fraction(1, 2);
  s['Q'] = fraction(1, 4);
  s['E'] = fraction(1, 8);
  s['S'] = fraction(1, 16);
  s['T'] = fraction(1, 32);
  s['X'] = fraction(1, 64);

  string line;
  while (cin >> line && line != "*") {
    int ans = 0;
    fraction acc(0);
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '/') {
        if (acc == fraction(1))
          ans++;
        acc = fraction(0);
      } else {
        acc = acc + s[line[i]];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
