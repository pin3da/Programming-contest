
#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


// Computes ( a ^ exp ) % mod.
long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    exp >>= 1;
  }
  return ans;
}


const int MP = 32768 * 10;
int sieve[MP];
long long primes[MP];



long long fun(long long base, long long exp, long long m) {
  return mod_pow(base, exp, m);
}

long long cp[12345 * 10];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string n;
  long long c, m;
  while (cin >> n >> c >> m) {
    cp[0] = 1;
    cp[1] = c % m;
    for (int i = 2; i <= n.size(); ++i) {
      long long a = cp[i - 1];
      long long next = 1;
      for (int j = 0; j < 10; ++j) {
        next = (next * a) % m;
      }
      cp[i] = next;
    }

    long long ans = 1;
    for (int i = n.size() - 1; i >= 0; --i) {
      int j = n.size() - i;
      ans = (ans * mod_pow(cp[j] ,(n[i] - '0'), m)) % m;
    }
    cout << ans << endl;
  }

  return 0;
}

