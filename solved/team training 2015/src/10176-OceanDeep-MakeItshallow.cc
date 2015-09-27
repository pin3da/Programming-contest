#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 131071;

ll mod_pow(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  string act, s;
  while (cin >> act) {
    s.clear();
    while (act.back() != '#') {
      s += act.substr(0, act.size());
      
      cin >> act;
    }
    s += act.substr(0, act.size() - 1);

    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans + (s[i] - '0') * mod_pow(2, n - i - 1)) % mod;
    
    ans %= mod;
    if (ans == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  return 0;
}
