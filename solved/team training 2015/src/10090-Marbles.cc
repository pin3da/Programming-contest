#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, d;
void ext_euclid(ll a, ll b) {
  if (b == 0){
    x = 1LL; y = 0LL; d = a;
    return;
  }
  ext_euclid(b, a % b);

  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

ll c1, c2;
ll cost (ll x, ll y) {
  return c1 * x + c2 * y;
}

int main() {
  ll n;
  ll n1, n2;
  while (cin >> n and n) {
    cin >> c1 >> n1 >> c2 >> n2;

    if (n % __gcd(n1, n2) != 0) {
      cout << "failed" << endl;
      continue;
    }

    ext_euclid(n1, n2);
    
    x = x * (n / d);
    y = y * (n / d);
    
    ll N1 = ceil(-double(x * d) / n2);
    ll x1 = x + n2 / d * N1;
    ll y1 = y - n1 / d * N1;

    ll N2 = floor(double(y * d) / n1);
    ll x2 = x + n2 / d * N2;
    ll y2 = y - n1 / d * N2;

    if (N1 > N2)  {
      cout << "failed" << endl;
      continue;
    }
    
    if (cost(x1, y1) <= cost(x2, y2)) {
      x = x1; y = y1;
    } else {
      x = x2; y = y2;
    }
    
    cout << x << " " << y << endl;
  }
  
  return 0;
}
