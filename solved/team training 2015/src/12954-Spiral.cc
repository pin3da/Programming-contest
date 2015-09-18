#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll func(ll k, ll n) {
  return 2 * n * k - k * k;
}

ll bs(ll n, ll b) {
  ll lo = 0, hi = n;
  while (hi - lo > 1) {
    ll mid = (hi + lo) >> 1;
    if (func(mid, n) < b)
      lo = mid;
    else
      hi = mid;
  }
  return hi;
}

pair<ll,ll> solve(ll n, ll b) {
  ll k = bs(n, b);
  ll f = func(k, n);
  bool down = k & 1;

  ll x, y;
  if (down) {
    y = n - (k >> 1); x = n - (k >> 1);
  } else {
    y = k >> 1; x = (k >> 1) + 1;
  }

  ll l = 2 * n - (2 * k - 1);
  if (down) {
    if (b < f - (l >> 1) + 1) {
      x -= (l >> 1);
      y -= (f - (l >> 1)) - b;
    } else {
      x -= f - b;
    }
  } else {
    if (b < f - (l >> 1) + 1) {
      x += (l >> 1);
      y += (f - (l >> 1)) - b;
    } else {
      x += f - b;
    }
  }

  cout << x << " " << y << endl;
}

int main() {
  ll n, b;
  while (cin >> n >> b)
    solve(n, b);
  
  return 0;
}
