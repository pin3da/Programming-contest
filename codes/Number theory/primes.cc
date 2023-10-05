namespace primes {
const int MP = 100001;
bool sieve[MP];
long long primes[MP];
int num_p;
void fill_sieve() {
  num_p = 0;
  sieve[0] = sieve[1] = true;
  for (long long i = 2; i < MP; ++i) {
	if (!sieve[i]) {
	  primes[num_p++] = i;
	  for (long long j = i * i; j < MP; j += i)
		sieve[j] = true;
	}
  }
}

// Finds prime numbers between a and b, using basic primes up to sqrt(b)
// a must be greater than 1.
vector<long long> seg_sieve(long long a, long long b) {
  long long ant = a;
  a = max(a, 3LL);
  vector<bool> pmap(b - a + 1);
  long long sqrt_b = sqrt(b);
  for (int i = 0; i < num_p; ++i) {
	long long p = primes[i];
	if (p > sqrt_b)
	  break;
	long long j = (a + p - 1) / p;
	for (long long v = (j == 1) ? p + p : j * p; v <= b; v += p) {
	  pmap[v - a] = true;
	}
  }
  vector<long long> ans;
  if (ant == 2)
	ans.push_back(2);
  int start = a % 2 ? 0 : 1;
  for (int i = start, I = b - a + 1; i < I; i += 2)
	if (pmap[i] == false)
	  ans.push_back(a + i);
  return ans;
}

vector<pair<int, int>> factor(int n) {
  vector<pair<int, int>> ans;
  if (n == 0)
	return ans;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
	if ((n % primes[i]) == 0) {
	  int expo = 0;
	  while ((n % primes[i]) == 0) {
		expo++;
		n /= primes[i];
	  }
	  ans.emplace_back(primes[i], expo);
	}
  }

  if (n > 1) {
	ans.emplace_back(n, 1);
  }
  return ans;
}
}  // namespace primes
