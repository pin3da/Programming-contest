#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long sum(long long x) {
  return ((x + 1) * (x)) >> 1;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b) {
    cout << sum(b) - sum(a - 1) << endl;
  }
  return 0;
}
