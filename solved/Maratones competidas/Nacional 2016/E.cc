#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

// return a % b (positive value)
int mod(int a, int b) {
  return ((a%b) + b) % b;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x - q*xx; x = t;
    t = yy; yy = y - q*yy; y = t;
  }
  return a;
}

// finds all solutions to ax = b (mod n)
vector<int> modular_linear_equation_solver(int a, int b, int n) {
  b %= n;
  b += n;
  b %= n;

  a %= n;
  a += n;
  a %= n;


  int x, y;
  vector<int> ret;
  int g = extended_euclid(a, n, x, y);
  if (!(b%g)) {
    x = mod(x*(b / g), n);
    for (int i = 0; i < g; i++)
      ret.push_back(mod(x + i*(n / g), n));
  }
  return ret;
}

const int MN = 333;
int a[MN], b[MN], c[MN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    int best = 10000;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      for (int j = 0; j < i; ++j) {
        vector<int> t = modular_linear_equation_solver(c[j] - c[i],
            b[i] - b[j], 360);
        if (t.size()) {
          best = min(best, *min_element(t.begin(), t.end()));
        }
      }
    }
    if (best < 1000) {
      cout << best << endl;
    } else {
      cout << "GIANIK IS NEVER ECLIPSED" << endl;
    }
  }

  return 0;
}
