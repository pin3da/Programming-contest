#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 40;

long long fib[MN], ans[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fib[0] = 0; fib[1] = 0;
  ans[0] = 0; ans[1] = 1;
  for (int i = 2; i < MN; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2] + 2;
    ans[i] = ans[i - 1] + ans[i - 2];
  }
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    cout << "fib(" << n << ") = " << fib[n] << " calls = " << ans[n] << endl;
  }
  return 0;
}
