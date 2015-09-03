#include <bits/stdc++.h>
using namespace std;

const int MN = 2000010;
vector<bool> is_prime(MN, true);

void prime_sieve() {
  is_prime[1] = false;
  for (int i = 2; i * i < MN; i++) {
    if (!is_prime[i])
      continue;
    
    for (int j = i * i; j < MN; j += i)
      is_prime[j] = false;
  }
}

int phi[MN];
void euler_sieve() {
  for (int i = 1; i < MN; i++)
    phi[i] = i;

  for (int i = 1; i < MN; i++)
    if (is_prime[i])
      for (int j = i; j < MN; j += i)
	phi[j] -= phi[j] / i;
}

int dp[MN];
int dphi(int n) {
  if (dp[n] != -1)
    return dp[n];

  if (phi[n] == 1)
    return dp[n] = 1;
  return dp[n] = (1 + dphi(phi[n]));
}

int main() {
  int tc; cin >> tc;
  prime_sieve();
  euler_sieve();
  memset(dp, -1, sizeof dp);
  for (int i = 1; i < MN; i++)
    dphi(i);

  for (int i = 1; i < MN; i++)
    dp[i] += dp[i - 1];
  
  while (tc--) {
    int a, b;
    cin >> a >> b;

    cout << dp[b] - dp[a - 1] << endl;
  }
  
  return 0;
}
