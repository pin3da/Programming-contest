#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

const int MN = 10000 + 1000;
int sieve[MN];
int phi[MN];
long long ans[MN];

void fill_sieve() {
  sieve[0] = sieve[1] = true;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      for (int j = i + i; j < MN; j += i)
        sieve[j] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  fill_sieve();
  for (int i = 1; i < MN; i++)
    phi[i] = i;

  for (int i = 1; i < MN; i++)
    if (!sieve[i]) // is prime
      for (int j = i; j < MN; j += i)
        phi[j] -= phi[j] / i;


  ans[0] = phi[0] + 1;
  for (int i = 1; i < MN; ++i) {
    ans[i] = phi[i] + ans[i - 1];
  }

  int p; cin >> p;
  while (p--) {
    int k, y;
    cin >> k >> y;
    cout << k << ' ';
    cout << ans[y] << endl;

  }
  return 0;
}
