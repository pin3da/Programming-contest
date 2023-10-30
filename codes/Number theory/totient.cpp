long long totient(long long n) {
  if (n == 1) return 0;
  long long ans = n;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
	if ((n % primes[i]) == 0) {
	  while ((n % primes[i]) == 0)
		n /= primes[i];
	  ans -= ans / primes[i];
	}
  }
  if (n > 1) {
	ans -= ans / n;
  }
  return ans;
}

void totientSieve(int n) {
  vector<int> phi(n + 1);
  for (int i = 0; i <= n; i++)
	phi[i] = i;

  for (int i = 2; i <= n; i++) {
	if (phi[i] == i) {
	  for (int j = i; j <= n; j += i)
		phi[j] -= phi[j] / i;
	}
  }
}