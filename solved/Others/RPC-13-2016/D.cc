#include<bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

const long long mod = 1e9 + 7;

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    string line; cin >> line;
    vector<int> a(line.size());
    a[0] = (line[0] - '0') % m;
    int div = a[0] == 0;
    for (int i = 1; i < (int)a.size(); ++i) {
      a[i] = (line[i] - '0') % m;
      a[i] = (a[i - 1] * 10 + a[i]) % m;
      if (a[i] == 0) div++;
    }
    if (div == 0 || a.back() != 0) 
      cout << 0 << endl;
    else
      cout << mod_pow(2, div - 1) << endl;
  }
  return 0;
}


