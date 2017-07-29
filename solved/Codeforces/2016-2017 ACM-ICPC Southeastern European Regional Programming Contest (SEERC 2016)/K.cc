#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

typedef long long hash_t;

const long long base = 29;
const long long mod = 1000000000 + 7;
const int MN = 5005;

hash_t p[MN];
hash_t pinv[MN];

bool check(vector<hash_t> &hash, int i, int j, hash_t total) {
  // [0, i - 1]
  // [i, j - 1]
  // [j, n]
  int n = hash.size();
  hash_t a = hash[i - 1];
  hash_t b = (((hash[j - 1] - hash[i - 1] + mod) % mod) * pinv[i]) % mod;
  hash_t c = (((hash[n - 1] - hash[j - 1] + mod) % mod) * pinv[j]) % mod;

  int len_a = i, len_b = j - i, len_c = n - j;
  assert(len_a + len_b + len_c == n);
  int len_ab = len_a + len_b;
  int len_ac = len_a + len_c;
  int len_bc = len_b + len_c;

  if ((a + (b * p[len_a]) % mod + (c * p[len_ab]) % mod) % mod == total)
    return true;
  if ((a + (c * p[len_a]) % mod + (b * p[len_ac]) % mod) % mod == total)
    return true;
  if ((b + (a * p[len_b]) % mod + (c * p[len_ab]) % mod) % mod == total)
    return true;
  if ((b + (c * p[len_b]) % mod + (a * p[len_bc]) % mod) % mod == total)
    return true;
  if ((c + (a * p[len_c]) % mod + (b * p[len_ac]) % mod) % mod == total)
    return true;
  if ((c + (b * p[len_c]) % mod + (a * p[len_bc]) % mod) % mod == total)
    return true;
  return false;
}


long long mod_pow(long long base, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  p[0] = 1;
  pinv[0] = 1;
  long long base_inv = mod_pow(base, mod - 2);
  for (int i = 1; i < MN; i++) {
    p[i] = (p[i - 1] * base) % mod;
    pinv[i] = (pinv[i - 1] * base_inv) % mod;
    assert((p[i] * pinv[i]) % mod == 1);
  }

  string target, cur;
  // cin >> target >> cur;
  cin >> cur >> target;

  hash_t h_total = 0;
  for (int i = 0; i < (int) target.size(); i++) {
    target[i] = tolower(target[i]);
    long long t = ((target[i] - 'a') * p[i]) % mod;
    h_total = (t + h_total) % mod;
  }

  vector<hash_t> hash_sum(cur.size());
  for (int i = 0; i < (int)cur.size(); i++) {
    cur[i] = tolower(cur[i]);
    hash_sum[i] = ((cur[i] - 'a') * p[i]) % mod;
    if (i)
      hash_sum[i] = (hash_sum[i] + hash_sum[i - 1]) % mod;
  }

  int n = cur.size();
  for (int i = 1; i < n; i++) { // start of second part
    for (int j = i + 1; j < n; ++j) { // start of third part
      if (check(hash_sum, i, j, h_total)) {
        cout << "YES" << "\n";
        string a = cur.substr(0, i);
        string b = cur.substr(i, j - i);
        string c = cur.substr(j, n - j);
        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
