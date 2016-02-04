#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = (1LL << 31) - 1;

long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    exp >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  cin >> n;
  cout << mod_pow(3, n, mod) << endl;
  return 0;
}

