#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
const int MN = 5842;
const long long inf = 2000000000LL + 10LL;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  vector<long long> dp(MN);
  dp[0] = 1;
  vector<int> idx(10);
  int primes[] = {2, 3, 5, 7};
  for (int i = 1; i < MN; ++i) {
    dp[i] = inf;
    for (int j = 0; j < 4; ++j)
      dp[i] = min(dp[i], primes[j] * dp[idx[primes[j]]]);

    for (int j = 0; j < 4; ++j)
      if (primes[j] * dp[idx[primes[j]]] == dp[i])
        idx[primes[j]]++;
  }

  int n;
  while (cin >> n && n) {
    cout << "The " << n;
    if (n % 100  == 12  || n % 100  == 11 || n % 100 == 13) cout << "th ";
    else {
      if (n % 10 == 1) cout << "st ";
      else if (n % 10 == 2) cout << "nd ";
      else if (n % 10 == 3) cout << "rd ";
      else cout << "th ";
    }
    cout << "humble number is ";
    cout << dp[n - 1] << "." << endl;

  }
  return 0;
}
