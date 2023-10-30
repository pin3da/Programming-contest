/*
F[mask] = sum(A[i]) for all i in mask
*/
// O(N x 2^N)
for (int i = 0; i < (1 << N); ++i)
  F[i] = A[i];
for (int i = 0; i < N; ++i)
  for (int mask = 0; mask < (1 << N); ++mask) {
	if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
  }

// O(3^N)
// iterate over all the masks
for (int mask = 0; mask < (1 << n); mask++) {
  F[mask] = A[0];
  // iterate over all the subsets of the mask
  for (int i = mask; i > 0; i = (i - 1) & mask) {
	F[mask] += A[i];
  }
}
