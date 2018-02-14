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
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  vector<vector<int>> ford(n, vector<int> (3));

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < 3; j++) {
      int tmp = a[i] == j;
      ford[i][j] = tmp;

      if (i) {
        ford[i][j] = max(ford[i][j], ford[i - 1][j] + tmp);
        ford[i][j] = max(ford[i][j], ford[i - 1][j - 1] + tmp);
      }
    }
  }

  vector<vector<int>> back(n, vector<int> (4));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j < 3; j++) {
      int tmp = a[i] == j;
      back[i][j] = tmp;

      if (i < (n - 1)) {
        back[i][j] = max(back[i][j], back[i + 1][j] + tmp);
        back[i][j] = max(back[i][j], back[i + 1][j + 1] + tmp);
      }
    }
  }


  int best = max(ford[n - 1][1], ford[n - 1][2]);

  for (int i = 0; i + 1 < n; i++) {
    best = max(best, ford[i][2] + back[i + 1][1]);
  }

  cout << best << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

