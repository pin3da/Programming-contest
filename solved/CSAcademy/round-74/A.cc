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


void solve() {
  int a, l, h;
  read(a, l, h);

  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= a; j++) {
      for (int k = 0; k <= a; k++) {
        if ((i + j + k) == a) {
          if (((2 * i + 4 * j + 4 * k) == l) && (2 * j + 1 * k) == h) {
            cout << k << endl;
            return;
          }
        }
      }
    }
  }
  cout << 0 << endl;
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

