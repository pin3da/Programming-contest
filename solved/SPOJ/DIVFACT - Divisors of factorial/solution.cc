#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int highest_exponent(int p, const int &n){
  int ans = 0;
  int t = p;
  while(t <= n){
    ans += n/t;
    t*=p;
  }
  return ans;
}

const int MN = 50010;
int p[MN];
int sieve[MN];

const long long mod = 1000 * 1000 * 1000 + 7;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;

  int ps = 0;
  sieve[0] = sieve[1] = true;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      p[ps++] = i;
      for (int j = i + i; j < MN; j += i)
        sieve[j] = 1;
    }
  }

  while (tc--) {
    int n; cin >> n;
    long long ans = 1;
    for (int i = 0; i < ps && p[i] <= n; ++i)
      ans = (ans * (highest_exponent(p[i], n) + 1)) % mod;
    cout << ans << endl;
  }

  return 0;
}
