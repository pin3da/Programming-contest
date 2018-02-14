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

bool all_inc(deque<int> &a) {
  for (int i = 1; i < int(a.size()); i++) {
    if (a[i] < a[i - 1]) return false;
  }
  return true;
}


void solve() {
  int n; cin >> n;
  deque<int> a(n);
  for (auto &i : a) cin >> i;

  if (all_inc(a)) {
    map<int, int> frec;
    int ways = 0;
    for (int i = 0; i < n; i++) {
      frec[a[i]]++;
      ways += frec[a[i]];
    }
    cout << ways << endl;
    cout << 1 << " " << 1 << endl;
    return;
  }

  deque<int> cur;

  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      int j = i;
      while (j < n && a[j] <= a[j - 1]) j++;

      int s = i - 1;
      while (s >= 0 && a[s] >= a[s + 1]) s--;
      s++;

      debug(s, j);

      reverse(a.begin() + s, a.begin() + j);
      if (all_inc(a)) {
        cout << 1 << endl;
        cout << s + 1 << " " << j << endl;
      } else {
        cout << 0 << endl;
      }
      return;
    }
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

