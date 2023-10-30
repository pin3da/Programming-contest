/*
DP Formula: dp[i][j] = min(dp[i-1][k-1] + C(k, j)) for 0 <= k <= j
Condition: opt[i][j] <= opt[i][j+1]
Proving opt: C(a, c) + C(b, d) <= C(a, d) + C(b, c) for all a <= b <= c <= d
*/
/*
The function compute computes one row i of states dp_cur, given the previous row i-1 of states dp_before. 
It has to be called with compute(0, n-1, 0, n-1). 
The function solve computes m rows and returns the result.
*/
int m, n;
vector<long long> dp_before(n), dp_cur(n);

long long C(int i, int j);

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
  if (l > r) return;

  int mid = (l + r) >> 1;
  pair<long long, int> best = {LLONG_MAX, -1};

  for (int k = optl; k <= min(mid, optr); k++) {
	best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
  }

  dp_cur[mid] = best.first;
  int opt = best.second;

  compute(l, mid - 1, optl, opt);
  compute(mid + 1, r, opt, optr);
}

int solve() {
  for (int i = 0; i < n; i++)
	dp_before[i] = C(0, i);

  for (int i = 1; i < m; i++) {
	compute(0, n - 1, 0, n - 1);
	dp_before = dp_cur;
  }

  return dp_before[n - 1];
}