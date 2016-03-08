#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long f[10];
  f[0] = f[1] = 1;
  for (int i = 2; i < 10; ++i)
    f[i] = f[i - 1] * i;

  long long a;
  while (cin >> a && a) {
    string b = to_string(a);
    long long ans = 0;
    for (int i = 0; i < b.size(); ++i) {
      ans += (b[i] - '0') * f[b.size() - i];
    }
    cout << ans << endl;
  }
  return 0;
}
