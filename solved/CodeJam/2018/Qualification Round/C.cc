#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

const int MN = 1123;
int seen[MN][20];

void solve() {
  int a; cin >> a;
  memset(seen, 0, sizeof seen);
  int finished = false;
  for (int i = 2; !finished; i += 3) {
    int missing = 9;
    while (missing > 0) {
      cout << i << " 3" << endl;
      int x, y; cin >> x >> y;
      if (x == 0 && y == 0) {
        finished = true;
        break;
      }
      if (seen[x][y] == 0) {
        seen[x][y] = true;
        missing--;
      }
    }
  }
}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
