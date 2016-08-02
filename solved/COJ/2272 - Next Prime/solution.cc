#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000000 + 100;
int sieve[MN];

vector<long long> p;

bool isp(long long n) {
  if (n == 2) return true;
  if (n == 1 || (n % 2) == 0) return 0;
  for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
      if (n % p[i]) continue;
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      p.push_back(i);
      for (int j = i + i; j < MN; j += i)
        sieve[j] = 1;
    }
  }

  int tc; cin >> tc;
  while (tc--) {
    long long n; cin >> n;
    while (!isp(n)) {
      n++;
    }
    cout << n << endl;
  }
  return 0;
}
