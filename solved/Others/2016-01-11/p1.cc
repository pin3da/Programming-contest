#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long f(long long x) {
  return (x * (x - 1)) >> 1;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  int t = 0;
  while (cin >> a >> b && a) {
    cout << "Case " << (++t) << ": ";
    cout << f(a) * f(b) << endl;
  }
  return 0;
}
