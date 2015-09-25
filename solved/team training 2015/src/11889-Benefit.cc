#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 10000100;
vector<ll> primes;

void sieve() {
  vector<bool> p(MN, true);
  p[0] = p[1] = false;
  int idx = 0;
  for (ll i = 2; i < MN; i++) {
    if (!p[i])
      continue;
    
    primes.push_back(i);
    for (ll j = i * i; j < MN; j += i)
       p[j] = false;
  }
}

map<ll,ll> fact(int n) {
  map<ll,ll> fn;
  for (int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      n /= primes[i];
      fn[primes[i]]++;
    }
  }

  if (n != 1)
    fn[n]++;
  return fn;
}

ll pow(int a, int b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

ll solve(ll a, ll c) {
  map<ll,ll> fa = fact(a), fc = fact(c);
  ll b = 1;
  
  map<ll,bool> found;
  for (auto& p : fa) {
    if (p.second < fc[p.first]) {
      if (!found[p.first])
	b *= pow(p.first, fc[p.first]);
      found[p.first] = true;
    }
    else if (p.second > fc[p.first])
      return -1;
  }

  for (auto& p : fc) {
    if (fa[p.first] < p.second) {
      if (!found[p.first])
	b *= pow(p.first, fc[p.first]);
      found[p.first] = true;
    }
    else if (fa[p.first] > p.second)
      return -1;
  }
  return b;
}

int main() {
  sieve();
  int tc; cin >> tc;
  while (tc--) {
    ll a, c;
    cin >> a >> c;
    ll ans = solve(a, c);
    if (ans == -1)
      cout << "NO SOLUTION" << endl;
    else
      cout << ans << endl;
  }
  
  return 0;
}
