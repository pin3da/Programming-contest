// WA on test 13 ):
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MN = 1 << 18;
long long a[MN];
long long ori[MN];

const long long prime = 2016 * 2017 + 1;

inline long long mult(long long a, long long b) {
  return (a * b) % prime;
}

inline long long add(long long a, long long b) {
  return (a + b) % prime;
}

void ntfft() {
  int n = MN;
  long long basew = 5;
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    long long w = 1;
    for (int i = 0; i < mh; i++) {
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        long long x = (a[j] - a[k] + prime) % prime;
        a[j] = (a[j] + a[k]) % prime;
        a[k] = (w * x) % prime;
      }
      w = mult(w, basew);
    }
    basew = mult(basew, basew);
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ori[i];
  }

  memcpy(a, ori, sizeof ori);
  ntfft();

  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum = (sum + a[i]) % prime;
  cout << sum << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

