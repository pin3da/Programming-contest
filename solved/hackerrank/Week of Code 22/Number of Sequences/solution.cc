#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout <<#x " = " << x << endl

using namespace std;

bool valid(vector<int> a) {
  for (int i = 1; i - 1 < a.size(); ++i) {
    for (int j = i + i; j - 1 < a.size(); j += i) {
      if ((a[i - 1] % i) != (a[j - 1] % i)) return false;
    }
  }
  return true;
}

vector<vector<int> > all;
void  gen(vector<int> a) {
  if (a.size() == 8) {
    if (valid(a)) all.push_back(a);
    return;
  }

  for (int i = 0; i <= a.size(); ++i) {
    vector<int> nxt = a;
    nxt.push_back(i);
    gen(nxt);
  }
}

const int MN = 1000100;
int sieve[MN];
int primes[MN];
int eprimes[MN];
int nump;

void fill_sieve() {
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[nump++] = i;
      for (int j = i; j < MN; j += i)
        sieve[j] = i;
    }
  }
}


long long mod_pow(long long b, long long e, long long m) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}

const long long mod = 1000000000LL + 7;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  fill_sieve();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ok = true;
  for (int i = 1; i <= n && ok; ++i) {
    for (int j = i; j - 1 < n && ok; j += i) {
      if (a[j - 1] != -1) {
        if (a[i - 1] == -1) a[i - 1] = a[j - 1] % i;
        else ok &= a[i - 1] == (a[j - 1] % i);
      }
    }
  }

  if (!ok) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      int t = i + 1;
      for (int j = 0; j < nump && primes[j] <= t; ++j) {
        int cur = 0;
        while ((t % primes[j]) == 0) {
          t /= primes[j];
          cur++;
        }
        eprimes[j] = max(eprimes[j], cur);
      }
    }
  }
  long long ans = 1;
  for (int i = 0; i < nump; ++i) {
    ans = (ans * mod_pow(primes[i], eprimes[i], mod)) % mod;
  }
  cout << ans << endl;

  gen(vector<int> ());
  int i = all.size() - 5;
    for (int j = 0; j < all[i].size(); ++j) {
      cout << all[i][j] << ' ';
    }
  cout << endl;
  return 0;
}
