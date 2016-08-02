#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;

const int MX = 1010005;
const long long MOD = 100000LL * 100000LL;
vector<long long> primes;
bool check[MX];

long long ans[MX];

void genP() {
  primes.push_back(2);
  for(int i = 3; i < MX; i += 2) {
    if(check[i]) continue;
    primes.push_back(i);
    for(int j = i + i; j < MX; j += i) check[j] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  genP();
  ans[0] = 1;
  int k = - 1, paila = false;
  for(int i = 0; i < primes.size(); i++) {
    if (primes[i] * ans[i] < MOD && !paila)
      k = i + 1;
    else
      paila = true;
    ans[i + 1] = (primes[i] * ans[i]) % MOD;
  }
  int t, x; cin >> t;

  while(t--) {
    cin >> x;
    auto it = upper_bound(primes.begin(), primes.end(), x);
    int id = it - primes.begin();
    if (id <= k) cout << ans[id] << endl;
    else {
      string tmp = to_string(ans[id]);
      int falta = 10 - tmp.size();
      cout << string(falta, '0') << tmp << endl;
    }
  }
  return 0;
}
