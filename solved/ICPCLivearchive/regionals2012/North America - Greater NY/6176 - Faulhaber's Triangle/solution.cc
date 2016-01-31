#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 430;

struct frac {
  ll num, den;
  frac() {num = 0; den = 1;}
  frac(ll a, ll b) {
    ll g = __gcd(a, b);
    a /= g; b /= g;

    ll sgn;
    if (a * b < 0)
      sgn = -1;
    else
      sgn = 1;
    a = llabs(a); b = llabs(b);
    num = sgn * a; den = b;
  }

  frac operator+(frac &x) {
    return frac(num * x.den + den * x.num, den * x.den);
  }

  frac operator-(frac &x) {
    return frac(num * x.den - den * x.num, den * x.den);
  }

  frac operator*(frac &x) {
    return frac(num * x.num, den * x.den);
  }
};

frac faul[MM][MM + 10];
void gen() {
  faul[0][1] = frac(1, 1);
  for (int i = 1; i < MM; i++) {
    frac sum;
    for (int j = 2; j <= i + 1; j++) {
      faul[i][j] = frac(i, j) * faul[i - 1][j - 1];
      sum = sum + faul[i][j];
    }
    faul[i][1] = frac(1, 1) - sum;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  gen();

  int p; cin >> p;
  while (p--) {
    int id; cin >> id;
    int i, j; cin >> i >> j;
    frac f = faul[i][j];

    cout << id << " ";
    if (f.den == 1)
      cout << f.num << endl;
    else
      cout << f.num << "/" << f.den << endl;
  }

  return 0;
}
