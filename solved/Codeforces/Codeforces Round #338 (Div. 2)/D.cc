//
// WA
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = 1000000007;
const int MN = 200000 + 10;

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

void solve(int n) {
  vector<int> frec(MN);
  vector<int> m(n);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    frec[t]++;
    m[i] = t;
  }

  deque<int> tmp;
  deque<int> val;
  for (int i = 0; i < MN; ++i) {
    if (frec[i]) {
      tmp.push_back(frec[i]);
      val.push_back(i);
    }
  }

  long long times = 1;
  for (int i = 0; i < tmp.size(); ++i)
    times = (times * (tmp[i] + 1)) % (mod - 1);

  long long two_inv = mod_pow(2, mod - 3, mod - 1);
  times = (times * two_inv) % (mod - 1);

  long long ans = 1;
  for (int i = 0; i < val.size(); ++i) {
    ans = (ans * mod_pow(val[i], (times) % (mod - 1), mod)) % mod;
  }

  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
