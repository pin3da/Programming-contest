namespace sievePrime {
vi primes;
const int MAX = 5e8 + 5;  // run in 2s
bitset<MAX> isPr;

void oddSieve() {  // Source: RR
  isPr.flip();
  isPr[0] = isPr[1] = 0;
  for (int i = 3; i * i < MAX; i += 2) {
	if (isPr[i]) {
	  int i2 = i + i;
	  for (int j = i * i; j < MAX; j += i2)
		isPr[j] = 0;
	}
  }
  primes.push_back(2);
  for (int i = 3; i < MAX; i += 2)
	if (isPr[i]) primes.push_back(i);
}

vector<pair<int, int>> sqrtFactor(int n) {  // < O(sqrt(N))
  vector<pair<int, int>> ans;
  if (n == 0) return ans;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
	if ((n % primes[i]) == 0) {
	  ans.push_back(make_pair(primes[i], 0));
	  while ((n % primes[i]) == 0) {
		ans.back().second++;
		n /= primes[i];
	  }
	}
  }

  if (n > 1) {
	ans.emplace_back(n, 1);
  }
  return ans;
}
}  // namespace sievePrime

namespace leastPrimeFactorSieve {
vector<int> primes;
const int MAX = 1e8 + 5;
int lp[MAX];  // least prime factor

void linearSieve() {  // O(MAX)
  for (int i = 2; i < MAX; ++i) {
	if (lp[i] == 0) {
	  lp[i] = i;
	  primes.push_back(i);
	}
	for (int j = 0; i < MAX / primes[j]; ++j) {
	  lp[i * primes[j]] = primes[j];
	  if (primes[j] == lp[i]) break;
	}
  }
}

vector<pair<int, int>> logFactor(int n) {  // < O(log(N)), N <= MAX required
  vector<pair<int, int>> ans;
  if (n == 0) return ans;
  while (n > 1) {
	int pr = lp[n];
	ans.push_back(make_pair(pr, 0));
	while (n % pr == 0) {
	  ans.back().second++;
	  n /= pr;
	}
  }
  return ans;
}
}  // namespace leastPrimeFactorSieve

vector<bool> segmentedSieve(ll L, ll R) {
  // generate all primes up to sqrt(R)
  ll lim = sqrt(R);
  vector<bool> mark(lim + 1, false);
  vector<ll> primes;
  for (long long i = 2; i <= lim; ++i) {
	if (!mark[i]) {
	  primes.emplace_back(i);
	  for (long long j = i * i; j <= lim; j += i)
		mark[j] = true;
	}
  }
  vector<bool> isPrime(R - L + 1, true);
  for (ll i : primes)
	for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
	  isPrime[j - L] = false;
  if (L == 1) isPrime[0] = false;
  return isPrime;
}
