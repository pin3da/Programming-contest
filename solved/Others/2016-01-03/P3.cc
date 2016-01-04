#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long f(long long x) {
  return (x * (x + 1)) >> 1;
}

void solve() {
  long long n; cin >> n;
  if (n < 0) n *= -1;
  for (long long i = 1; ; ++i) {
    if (f(i) >= n) {
      while ((f(i) - n) & 1) {
        i++;
      }
      cout << i << endl;
      return;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n; cin >> n;
  int tc = 0;
  while (n --) {
    if (tc) cout << endl;
    tc = 1;
    solve();
  }
  return 0;
}
