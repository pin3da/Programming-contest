#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MP = 2000123;
bool sieve[MP];
long long primes[MP];
long long gap[MP];
int num_p;
void fill_sieve() {
  num_p = 0;
  sieve[0] = sieve[1] = true;
  for (long long i = 2; i < MP; ++i) {
    if (!sieve[i]) {
      primes[num_p++] = i;
      for (long long j = i * i; j < MP; j += i)
        sieve[j] = true;
    }
  }
}


const int MN = 1000123 + 10; // Max number of elements
const int ML = 22; // ceil(log2(MN));

struct st {
  int M[MN][ML];
  int n;

  void build(int n) {
    for (int i = 0; i < n; ++i)
      M[i][0] = gap[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = max(M[i][j - 1], M[i + q][j - 1]);
  }
  int query(int b, int e) {
    int k = log2(e - b + 1);
    return max(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};

st rmq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_sieve();
  for (int i = 1; i < num_p; i++) {
    gap[i - 1] = primes[i] - primes[i - 1];
  }

  rmq.build(num_p - 1);

  long long a, b;
  while (cin >> a >> b && (a + b)) {
    if (a > b)
      swap(a, b);
    int id_a = lower_bound(primes, primes + num_p, a) - primes;
    int id_b = upper_bound(primes, primes + num_p, b) - primes - 1;
    if (id_b < id_a) {
      cout << "NULL" << endl;
    } else {
      cout << rmq.query(id_a, id_b) << endl;
    }
  }

  return 0;
}
