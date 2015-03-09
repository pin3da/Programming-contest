using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

/*
 * Let M = F·G·(min(deg f, deg g)+1), where F is the greatest coefficient in f and G is the greatest coefficient in g.
 * rou_i = kth root of unity mod p_i.
 * The following must be hold for each prime:
 *   k > 2 * max_degree(f, g)
 *   p1·p2·...·pl > 2M
 * */

long long _mod[] = {1711276033LL, 1790967809LL};
long long _rou[] = {1223522572LL, 1110378081LL};
const vector<long long> mod(_mod, _mod + 2);
const vector<long long> rou(_rou, _rou + 2);
// these are the 2 ^ 18th root of unity mod the above primes.
const int MN = (1 << 18);

typedef long long ll;

long long mod_pow(long long base, long long exp, long long m) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * base) % m;
    base = (base * base) % m;
    exp >>= 1;
  }
  return ans % m;
}

ll inv(ll a, ll m) {
  return mod_pow(a, m - 2, m);
}

ll modMul (ll a, ll b , ll m) {
  ll ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a);
      if (ans > m)
        ans -= m ;
      b--;
    }
    else {
      a = a + a;
      if (a > m)
        a -= m;
      b >>= 1;
    }
  }
  return ans;
}

vector<ll> crt(vector<ll> &a, vector<ll> &b) {
  ll n = a.size();
  vector<ll> A(n);
  ll M = mod[0] * mod[1];
  for (int i = 0; i < n; i++)
    A[i] = (modMul(modMul(a[i], mod[1], M), inv(mod[1], mod[0]), M)%M + modMul(modMul(b[i],mod[0], M), inv(mod[0], mod[1]), M)%M ) % M;

  return A;
}


int bit_reverse(int x, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++)
    if ((x >> i) & 1)
      ans |= ((1 << (n - i - 1)));
  return ans;
}

void bit_reverse_copy(vector<ll> &a, vector<ll> &A, int n) {
  A.resize(a.size());
  for (int i = 0; i < a.size(); i++)
    A[bit_reverse(i, n)] = a[i];
}

vector<ll> powers(25);

vector<ll> fft(vector<ll> &a, int dir, int index) {
  int ln = ceil(log2(a.size()));
  vector<ll> A;
  bit_reverse_copy(a, A, ln);
  for (int s = 1; s <= ln; s++) {
    long long m = (1LL << s);
    ll wm = powers[ln - s];
    if (dir == -1)
      wm =  inv(wm, mod[index]);

    for (int k = 0; k < a.size(); k += m) {
      ll w = 1, mh = m >> 1;
      for (int j = 0; j < mh; j++) {
        ll t = (w * A[k + j + mh]) % mod[index];
        ll u = A[k + j];
        A[k + j] = (u + t) % mod[index];
        A[k + j + mh] = (u - t + mod[index]) % mod[index];
        w = (w * wm) % mod[index];
      }
    }
  }

  if (dir < 0) {
    ll in = inv(A.size(), mod[index]);
    for (int i = 0; i < A.size(); i++)
      A[i] = (A[i] * in) % mod[index];
  }

  return A;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  string line;
  vector<long long> a(MN), b(MN), c(MN);
  powers[0] = rou[1];
  for (int i = 1; i < 25; ++i) {
    powers[i] = (powers[i - 1] * powers[i - 1]) % mod[1];
  }

  while (n--) {
    fill(a.begin(), a.end(), 0);
    fill(b.begin(), b.end(), 0);
    fill(c.begin(), c.end(), 0);
    int s1, s2;
    cin >> line;
    s1 = line.size();
    for (int i = 0; i < line.size(); ++i)
      a[i] = line[line.size() - i - 1] - '0';

    cin >> line;
    s2 = line.size();
    for (int i = 0; i < line.size(); ++i)
      b[i] = line[line.size() - i - 1] - '0';

    a = fft(a, 1, 1);
    b = fft(b, 1, 1);

    for (int i = 0; i < MN; ++i) {
      c[i] = (a[i] * b[i]) % mod[1];
    }

    c = fft(c, -1, 1);

    int carry = 0;
    deque<int> ans;
    for (int i = 0; i < 10; ++i) {
      ans.push_front((c[i] + carry) % 10);
      carry = (c[i] + carry) / 10;
    }

    while (ans.size() > 1 && ans.front() == 0) ans.pop_front();

    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
