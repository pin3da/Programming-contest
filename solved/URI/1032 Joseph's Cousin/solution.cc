#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 50005;
int primes[MN];
int sieve[MN];

int N;
int josephus(int n) {
  if (n == 1) return 0;
  int k = primes[N - n];
  return (josephus(n - 1) + k) % n;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  sieve[0] = sieve[1] = true;
  int p = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[p++] = i;
      for (int j = i + i; j < MN; j += i)
        sieve[j] = true;
    }
  }

  while (cin >> N && N) {
    cout << josephus(N) + 1 << endl;
  }
  return 0;
}
