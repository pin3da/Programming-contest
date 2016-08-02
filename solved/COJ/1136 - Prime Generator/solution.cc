#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl


typedef vector<long long> IV;
typedef vector<bool> BV;
typedef long long i64;

// Prime sieve
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP	 = 46341;  // sqrt(2^31)
const int SQRP	 = 216;    // sqrt(MAX)
const int MAX_NP = 5435;   // 1.26 * MAXP/log(MAXP)
int _c[(MAXP>>6)+1];
int primes[MAX_NP];
int nprimes;
void prime_sieve() {
  nprimes = 0;
  for (int i = 3; i <= SQRP; i += 2)
    if (!IsComp(i)) for (int j = i*i; j <= MAXP; j+=i+i) SetComp(j);
  primes[nprimes++] = 2;
  for (int i=3; i <= MAXP; i+=2) if (!IsComp(i)) primes[nprimes++] = i;
}
bool is_prime(int n) {
  if (n < 2 || (n > 2 && n % 2 == 0)) return false;
  return ! IsComp(n);
}

// Finds prime numbers between a and b, using basic primes up to sqrt(b)
// pre cond: a > 2 (handle that separately)
void prime_seg_sieve(i64 a, i64 b, IV &seg_primes) {
  BV pmap(b - a + 1, true);
  i64 sqr_b = sqrt(b);
  for (int i = 0; i < nprimes; ++i) {
    // For (IV, pp, primes) {
    int p = primes[i];
    if (p > sqr_b) break;
    for (i64 j = (a+p-1)/p, v=(j==1?p+p:j*p); v <= b; v += p)
      pmap[v-a] = false;
  }
  seg_primes.clear();
  for (int i = a%2 ? 0 : 1, I = b - a + 1; i < I; i += 2)
    if (pmap[i])
      seg_primes.push_back(a + i);
  }


  int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    prime_sieve();

    int tc; cin >> tc;
    while (tc--) {
      long long a, b;
      cin >> a >> b;
      if (b < a) swap(a, b);
      vector<long long> ans;
      prime_seg_sieve(max(a, 3LL), b, ans);
      if (a <= 2) cout << 2 << endl;
      for (auto &i : ans)
        cout << i << endl;
      cout << endl;
    }

    return 0;
  }
