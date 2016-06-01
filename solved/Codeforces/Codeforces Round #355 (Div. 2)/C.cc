#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int base(char t) {
  if (t >= '0' && t <= '9') return t - '0';
  if (t >= 'A' && t <= 'Z') return t - 'A' + 10;
  if (t >= 'a' && t <= 'z') return t - 'a' + 36;
  if (t == '-') return 62;
  return 63;
}
const long long mod = 1000 * 1000 * 1000 + 7;

int all[64];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;

  for (int i = 0; i < 64; ++i)
    for (int j = 0; j < 64; ++j)
      for (int k = 0; k < 64; ++k)
        if ((k & j) == i) all[i]++;

  while (cin >> line) {
    vector<int> a(line.size());
    for (int i = 0; i < line.size(); ++i)
      a[i] = base(line[i]);
    long long ans = 1;

    for (int i = 0; i < a.size(); ++i) {
      long long cur = all[a[i]];
      ans = (ans * cur) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
