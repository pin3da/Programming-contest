#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
const int MP = 5800000;
const ui MN = 100000010;
int np;
ui p[MP], prod[MP];
// pair<ui,ui> pp[MP]; // (p^k, p)

void prime_sieve() {
  vector<ui> is_prime(3125010, 0);
#define test(i) (is_prime[i >> 5] & (1 << (i & 31)))
#define set(i)  is_prime[i >> 5] |= (1 << (i & 31))

  set(1);
  for (ll i = 3; i * i < MN; i += 2)
    if (!test(i))
      for (ll j = i * i; j < MN; j += (i << 1))
	set(j);

  np = 0;
  p[np++] = 2;
  for (ui i = 3; i < MN; i += 2)
    if (!test(i))
      p[np++] = i;
  
  // npp = 0;
  // for (ui acum = 2; acum < MN; acum <<= 1)
  //   pp[npp++] = make_pair(acum, 2);
  
  // for (ll i = 3; i < MN; i += 2)
  //   if (!test(i)) {
  //     pp[npp++] = make_pair(i, i);
  //     for (ll acum = i * i; acum < MN; acum *= i)
  // 	pp[npp++] = make_pair(acum, i);
  //   }

  // sort(pp, pp + npp);
}

void prod_sieve() {
  prod[0] = 2;
  for (int i = 1; i < np; i++)
    prod[i] = prod[i - 1] * p[i];
  // for (int i = 1; i < npp; i++)
  //   pp[i].second *= pp[i - 1].second;
}

ui prod_sqrt(ll n) {
  ui ans = 1;
  for (int i = 0; p[i] * p[i] <= n; i++) {
    ui act = n / p[i], pk = 1;
    while (act >= p[i]) {
      act /= p[i];
      pk *= p[i];
    }
    ans *= pk;
  }
  return ans;
}

// int bs(ui n) {
//   int lo = -1, hi = npp + 1;
//   while (hi - lo > 1) {
//     ll mid = lo + ((hi - lo) >> 1);
//     if (pp[mid].first <= n)
//       lo = mid;
//     else
//       hi = mid;
//   }
//   return lo;
// }

int main() {
  prime_sieve();
  // cout << npp << endl;
  // for (int i = 0; i < 100; i++)
  //   cout << pp[i].first << " ";
  // cout << endl;
  prod_sieve();
  // cout << endl;
  // for (int i = 0; i < 100; i++)
  //   cout << pp[i].second << " ";
  // cout << endl;

  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    ll n;
    scanf("%lld", &n);
    ui ans = prod_sqrt(n);
    int pos = (upper_bound(p, p + np, n) - p) - 1; // bs(n);
    printf("Case %d: %u\n", i + 1, ans * prod[pos]);
  }

  return 0;
}
