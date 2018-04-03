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

namespace primes {
  const int MP = 10000001;
  bool sieve[MP];
  long long primes[MP];
  int num_p;
  void fill_sieve() {
    num_p = 0;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i < MP; ++i) {
      if (!sieve[i]) {
        primes[num_p++] = i;
        for (long long j = i * i; j < MP; j += i)
          sieve[j] = true;
      }
    }
  }

  vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ans;
    if (n == 0) return ans;
    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
      if ((n % primes[i]) == 0) {
        int expo = 0;
        while ((n % primes[i]) == 0) {
          expo++;
          n /= primes[i];
        }
        ans.emplace_back(primes[i], expo);
      }
    }

    if (n > 1) {
      ans.emplace_back(n, 1);
    }
    return ans;
  }
}

void solve() {
  primes::fill_sieve();

  debug(primes::num_p);

  int n; cin >> n;
  vector<int> a(n);
  read(a);

  int last = 0, ok = true;
  set<int> seen;
  for (int i = 0; i < n; i++) {
    auto cur = primes::factor(a[i]);
    for (auto it : cur) {
      if (seen.count(it.first)) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    for (auto it : cur)
      seen.insert(it.first);
    last = i;
  }

  vector<int> ans;
  for (int i = 0; i <= last; i++)
    ans.push_back(a[i]);

  if (last + 1 < n) {
    while (true) {
      a[last + 1]++;
      auto cur = primes::factor(a[last + 1]);
      int ok = true;
      for (auto it : cur) {
        if (seen.count(it.first)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans.push_back(a[last + 1]);
        for (auto it : cur)
          seen.insert(it.first);
        break;
      }
    }

    last++;

    int id = 0;
    for (int i = last + 1; i < n; i++) {
      while (seen.count(primes::primes[id])) {
        id++;
      }
      ans.push_back(primes::primes[id++]);
    }
  }

  assert(ans.size() == n);

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
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

