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


void solve() {
  long long n, a, b;
  read(n, a, b);

  if (a == 1 || b == 1) {
    for (int i = 1; i <= n; i++)
      cout << i << " ";
    cout << endl;
    return;
  }

  long long g = __gcd(a, b);
  if (n % g) {
    cout << -1 << endl;
    return;
  }


  long long x = 0, y = -1;
  for ( ;x < n; x++) {
    long long t = n - a * x;
    if (t >= 0 && (t % b) == 0) {
      y = t / b;
      break;
    }
  }

  if ((x * a + b * y) != n) {
    cout << -1 << endl;
    return;
  }

  debug(x, y);

  vector<int> ans(n);

  int s = 0;
  while (s < n) {

    while (x--) {
      debug(s);
      for (int i = 0; i + 1 < a; i++) {
        ans[s + i] = (s + i + 1) % n;
      }
      ans[(s + a - 1) % n] = s;
      s += a;
    }

    while (y--) {
      for (int i = 0; i + 1 < b; i++) {
        ans[s + i] = (s + i + 1) % n;
      }
      ans[(s + b - 1) % n] = s;
      s += b;
    }
  }

  assert(s == n);

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 <<  " ";
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

