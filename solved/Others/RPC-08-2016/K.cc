#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


typedef vector<int> VI;
typedef pair<int, int> PII;

// return a % b (positive value)
long long mod(long long a, long long b) {
  return ((a%b) + b) % b;
}

// computes gcd(a,b)
long long gcd(long long a, long long b) {
  while (b) { long long t = a%b; a = b; b = t; }
  return a;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
long long extended_euclid(long long a, long long b, long long &x, long long &y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a / b;
    long long t = b; b = a%b; a = t;
    t = xx; xx = x - q*xx; x = t;
    t = yy; yy = y - q*yy; y = t;
  }
  return a;
}


// computes b such that ab = 1 (mod n), returns -1 on failure
long long mod_inverse(long long a, long long n) {
  long long x, y;
  long long g = extended_euclid(a, n, x, y);
  if (g > 1) return -1;
  return mod(x, n);
}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    long long r, s, q;
    cin >> r >> s >> q;
    s *= -1;
    long long g = gcd(r,s);
    r /= g;
    s /= g;
    q /= g;
    long long x, y;
    extended_euclid(r, s, x, y);
    long long a = (q * x) % s;
    if (a <= 0) a += s;
    a += s * (q / r + 2);
    while ((a - s) * r > q) a -= s;
    long long b = (a * r - q) / s;
    cout << a << " " << b << endl;
  }
  return 0;
}
