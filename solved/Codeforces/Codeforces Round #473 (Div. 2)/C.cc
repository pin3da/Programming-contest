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


void print_wrong(int n) {
  if (n >= 6) {
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "2 4" << endl;
    for (int i = 5; i <= n; i++) {
      cout << "4 " << i << endl;
    }
  } else {
    cout << -1 << endl;
  }
}

void print_good(int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << i + 1 << " " << i + 2 << endl;
  }
}

void solve() {
  int n; cin >> n;
  print_wrong(n);
  print_good(n);
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

