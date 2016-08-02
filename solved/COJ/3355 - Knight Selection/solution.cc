#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 3333;
int ans[MN];

int main() {
  ios_base::sync_with_stdio(false);
  int n;

  for (int i = 6; i < MN; ++i) {
    int primes = 0;
    int cp = i;
    for (int j = 2; cp > 1; ++j) {
      if ((cp % j) == 0) {
        primes++;
        while ((cp % j) == 0) cp /= j;
      }
    }
    if (primes == 2)
    ans[i]++;
  }
  for (int i = 1; i < MN; ++i) {
    ans[i] += ans[i - 1];
  }
  while (cin >> n) {
    cout << ans[n] << endl;
  }
  return 0;
}
