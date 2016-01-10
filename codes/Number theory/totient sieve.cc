for (int i = 0; i < MP; ++i) phi[i] = i;

for (int i = 0; primes[i] <= 5000000; ++i) {
    phi[primes[i]] = primes[i] - 1;
    for (i64 j = 2 * primes[i]; j <= 5000000; j += primes[i]) {
        phi[j] = phi[j] * (primes[i]-1);
        phi[j] = phi[j] / primes[i];
    }
}
