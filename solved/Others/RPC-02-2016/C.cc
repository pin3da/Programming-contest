#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) cout << #x " = " << (x) << endl

const int MN = 1000000;
int sieve[MN];
int p[MN];
int ps;

void fill_sieve() {
  ps = 0;
  sieve[1] = sieve[0] = 1;
  for (int i = 2; i < MN; ++i) {
    if (sieve[i] == 0) {
      p[ps++];
      for (int j = i; j < MN; j += i) {
        sieve[j] = i;
      }
    }
  }
}

int solve(int n) {
  if (n == 0) return 0;
  return solve(n - sieve[n]) + 1;
}

int main() {
  long long n;
  fill_sieve();
  while (cin >> n) {
    cout <<	solve(n) << endl;
  }
  return 0;
}
