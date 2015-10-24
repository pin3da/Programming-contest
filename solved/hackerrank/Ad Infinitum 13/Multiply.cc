using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 1000001;
const long long mod = 1000000007;

struct ht {
  int _s[(MN + 10) >> 5];
  int len;
  void set(int id) {
    len++;
    _s[id >> 5] |= (1LL << (id & 31));
  }
  bool is_set(int id) {
    return _s[id >> 5] & (1LL << (id & 31));
  }
};

ht sieve;
const int MP = 78498 + 10;
int p[MP];
unordered_map<int, int> idx;

void fill_p() {
  sieve.set(0);
  sieve.set(1);
  int S = 1000;
  for (int i = 2; i <= S; ++i)
    if (!sieve.is_set(i))
      for (int j = i * i; j < MN; j += i)
        sieve.set(j);

  int j = 0;
  for (int i = 0; i < MN; ++i)
    if (!sieve.is_set(i)) {
      idx[i] = j;
      p[j] = i;
      j++;
    }

}

vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> ans;
  for (int i = 0; p[i] * p[i] <= n; ++i) {
    if (n % p[i]) continue;
    int e = 0;
    for (; n % p[i] == 0; e++, n /= p[i]);
    ans.push_back(make_pair(i, e));
  }
  if (n > 1)
    ans.push_back(make_pair(idx[n], 1));
  return ans;
}

int ex[MP];

struct seg_tree {
  int n;  // array size
  long long t[2 * MP];

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = (t[i<<1] * t[i<<1|1]) % mod;
  }

  // Single modification, range query.
  void modify(int p, long long value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] * t[p^1]) % mod;
  }

  long long query(int l, int r) {  // sum on interval [l, r)
    long long res = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = (res * t[l++]) % mod;
      if (r&1) res = (res * t[--r]) % mod;
    }
    return res;
  }

};

seg_tree num, den;

long long mod_pow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

void update(vector<pair<int, int>> &t) {
  for (int i = 0; i < t.size(); ++i) {
    ex[t[i].first] += t[i].second;
    long long expo = ex[t[i].first];
    long long val =  mod_pow(p[t[i].first], expo + 1) - 1;
    if (val < 0) val += mod;
    num.modify(t[i].first, val);
    den.modify(t[i].first, p[t[i].first] - 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fill_p();
  num.n = MP;
  den.n = MP;
  for (int i = 0; i < 2 * MP; ++i) {
    num.t[i] = den.t[i] = 1;
  }

  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> t = factorize(n);
  update(t);

  for (int i = 0; i < q; ++i) {
    int x; cin >> x;
    t = factorize(x);
    update(t);
    // cout << num.query(0, 10) << " / "  << den.query(0, 10) << endl;
    long long inv = mod_pow(den.query(0, MP), mod - 2);
    cout << (num.query(0, MP) * inv) % mod << endl;
  }

  return 0;
}
