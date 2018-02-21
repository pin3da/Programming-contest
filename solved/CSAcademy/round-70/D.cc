#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

void print_ans(vector<long long> &a, long long n) {
  long long acc = 0;
  for (int i = 0; i < int(a.size()); i++) {
    if (i) cout << " ";
    cout << a[i];
    if (i) assert(a[i] != a[i - 1]);
    acc += a[i];
  }
  cout << endl;
  assert(acc == n);
}

void solve() {
  long long n, k;
  read(n, k);

  long long base = n / k;
  long long extra = n - base * k;

  debug(base);

  if (base > 1) {
    vector<long long> ans(k, base);

    if (extra == k / 2) {
      for (int w = 0; w < 2; w++)
        for (int i = 1; i < k && extra; i += 2) {
          ans[i]++;
          extra--;
        }
    } else {
      for (int i = 0; i + 1 < k; i += 2) {
        ans[i]++;
        ans[i + 1]--;
      }
      if (extra && (k & 1)) {
        ans[k - 1]++;
        extra--;
      }

      for (int i = 0; i < k && extra; i++) {
        if (ans[i] == (base - 1)) {
          ans[i]++;
          extra--;
        }
      }
      for (int i = 0; i < k && extra; i++) {
        if (ans[i] == (base + 1)) {
          ans[i]++;
          extra--;
        }
      }

    }
    print_ans(ans, n);
  } else {
    long long extra = n - k;
    vector<long long> ans(k, 1);
    debug(extra);

    if (extra < (k / 2)) {
      cout << -1 << endl;
      return;
    }

    int start = 0;
    if (extra == (k / 2))
      start = 1;

    for (int w = 0; w < 2; w++)
      for (int i = start; i < k && extra; i += 2) {
        ans[i]++;
        extra--;
      }

    print_ans(ans, n);
  }
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

