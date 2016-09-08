#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 100000 + 100;
int sieve[MN];
int phi[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      for (int j = i + i; j < MN; j += i)
        sieve[j] = 1;
    }
  }

  for (int i = 1; i < MN; i++)
    phi[i] = i;

  for (int i = 1; i < MN; i++)
    if (!sieve[i]) // is prime
      for (int j = i; j < MN; j += i)
        phi[j] -= phi[j] / i;

  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    cout << phi[n] << endl;
  }

  return 0;
}
