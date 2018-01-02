#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const long long mod = 1e9 + 7;
const int MN = 1e5 + 100;

long long fact[MN];

long long mult(long long a, long long b) {
  return (a * b) % mod;
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = mult(ans, b);
    b = mult(b, b);
    e >>= 1;
  }
  return ans;
}

long long mod_inv(long long x) {
  return mod_pow(x, mod - 2);
}

long long comp_even(vector<int> &frec) {
  int total = 0;
  long long den = 1;
  for (int i = 0; i < (int)frec.size(); i++) {
    if ((frec[i] & 1) == 0) {
      den = mult(den, mod_inv(fact[frec[i] / 2]));
      total += frec[i] / 2;
    }
  }

  return mult(fact[total], den);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  fact[0] = 1;
  for (int i = 1; i < MN; i++) {
    fact[i] = mult(fact[i - 1], i);
  }

  string line;
  cin >> line;
  vector<vector<int>> frec(line.size(), vector<int>(26));

  for (int i = 0; i < (int)line.size(); i++) {
    if (i)
      frec[i] = frec[i - 1];
    frec[i][line[i] - 'a']++;
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    vector<int> diff(26);
    int odd = 0;
    for (int i = 0; i < 26; i++) {
      diff[i] = frec[r][i];
      if (l) diff[i] -= frec[l - 1][i];
      if (diff[i] & 1) {
        odd++;
        diff[i]--;
      }
    }

    /*
    cout << "---" << endl;
    for (auto it: diff) {
      cout << it << endl;
    }
    cout << "---" << endl;
    */

    long long ways = comp_even(diff);
    odd = max(1, odd);

    cout << mult(ways, odd) << endl;
  }
  return 0;
}
