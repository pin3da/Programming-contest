#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = 1000LL * 1000LL * 1000LL + 7;
long long mod_pow(long long b, long long e, long long m) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    string line; cin >> line;

    vector<int> pre(line.size());
    int ans = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (i) pre[i] = (pre[i - 1] * 10);
      pre[i] += line[i] - '0';
      pre[i] %= m;
      if (pre[i] == 0) ans++;
    }
    if (pre[line.size() - 1] || ans == 0)
      cout << 0 << endl;
    else
      cout << mod_pow(2, ans - 1, mod) << endl;
  }
  return 0;
}
