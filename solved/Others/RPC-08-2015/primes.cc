using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int rounds = 20;

// Computes (a * b) % mod
long long mod_mul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}

// Computes ( a ^ exp ) % mod.
long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = mod_mul(ans, a, mod);
    a = mod_mul(a, a, mod);
    exp >>= 1;
  }
  return ans;
}

// checks whether a is a witness that n is not prime, 1 < a < n
bool witness(long long a, long long n) {
  // check as in Miller Rabin Primality Test described
  long long u = n - 1;
  int t = 0;
  while (u % 2 == 0) {
    t++;
    u >>= 1;
  }
  long long next = mod_pow(a, u, n);
  if (next == 1) return false;
  long long last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    if (next == 1) {
      return last != n - 1;
    }
  }
  return next != 1;
}


// Checks if a number is prime with prob 1 - 1 / (2 ^ it)
//  D(miller_rabin(99999999999999997LL) == 1);
//  D(miller_rabin(9999999999971LL) == 1);
//  D(miller_rabin(7907) == 1);
bool miller_rabin(long long n, int it = rounds) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) {
    long long a = rand() % (n - 1) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}


bool inv(long long n, long long &ans) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  string t = s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '4' || s[i] == '3' || s[i] == '7')
      return false;
    if (s[i] == '9')
      t[i] = '6';
    if (s[i] == '6')
      t[i] = '9';
  }

  reverse(t.begin(), t.end());
  stringstream a(t);
  a >> ans;
  return true;
}

int main() {
  long long n;
  cin >> n;
  if (miller_rabin(n, rounds)) {
    long long t;
    if (inv(n, t)) {
    if (miller_rabin(t, rounds))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
    } else {
      cout << "no" << endl;
    }
  } else {
    cout << "no" << endl;
  }

  return 0;
}
