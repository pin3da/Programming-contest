#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MX = 5000000;

vector<ll> primes;
bool check[MX];

void genP() {
  primes.push_back(2);
  for(int i = 3; i < MX; i++) {
    if(check[i]) continue;
    primes.push_back(i);
    for(int j = i + i; j < MX; j += i) {
      check[j] = true;
    }
  }
}

vector<ll> factorize(ll x) {
  vector<ll> ans;
  for(int i = 0; i < primes.size() && primes[i] * primes[i] <= x ; i++) {
    if(x % primes[i] == 0) {
      while(x % primes[i] == 0 ){
        ans.push_back(primes[i]);
        if(ans.size() > 2) return ans;
        x /= primes[i];
      }
    }
  }
  if(x > 1) ans.push_back(x);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  genP();
  ll x;int t; cin >> t;
  while(t--) {
     cin >> x;
     vector<ll> ans = factorize(x);
     if(ans.size() == 1 || x == 1) {
      cout << "Vasha" << endl << 0 << endl;
     }else if(ans.size() == 2){
      cout << "Molek" << endl;
     }else{
      cout << "Vasha" << endl << ans[0] * ans[1] << endl;
     }
  }
}
