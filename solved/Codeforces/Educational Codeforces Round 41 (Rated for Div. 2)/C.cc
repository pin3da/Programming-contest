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

typedef vector<vector<int>> board;

int go(board &b, int s) {
  int cost = 0;
  int n = b.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cost += (b[i][j] ^ s);
      s ^= 1;
    }
  }
  return cost;
}

void solve() {
  int n; cin >> n;
  vector<board> pieces(4, board(n, vector<int>(n)));
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char t; cin >> t;
        pieces[k][i][j] = (t == '1');
      }
    }
  }

  vector<int> id = {0, 1, 2, 3};
  int best = 100000;
  vector<int> col = {0, 1, 1, 0};
  do {

    int cost = 0;
    for (int i = 0; i < 4; i++) cost += go(pieces[id[i]], col[i]);
    best = min(best, cost);
    cost = 0;
    for (int i = 0; i < 4; i++) cost += go(pieces[id[i]], col[i] ^ 1);
    best = min(best, cost);
  } while(next_permutation(id.begin(), id.end()));
  cout << best << endl;
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

