#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<char>> board(4, vector<char> (n, '.'));
  cout << "YES" << endl;
  if ((k & 1) == 0) {
    for (int i = 1; i <= k / 2; i++) {
      board[1][i] = board[2][i] = '#';
    }
  } else {
    if (k < 5) {
      int center = n / 2;
      int extra = k / 2;
      board[1][center] = '#';
      for (int i = 1; i <= extra; i++) {
        board[1][center + i] = board[1][center - i] = '#';
      }
    } else {
      k -= 5;
      for (int i = 1; i <= k / 2; i++) {
        board[1][i] = board[2][i] = '#';
      }
      int col = (k / 2) + 1;
      board[1][col + 2] = board[2][col + 2] = '#';
      board[2][col] = board[1][col] = '#';
      board[2][col + 1] = '#';
    }
  }
  for (auto row : board) {
    for (auto c : row)
      cout << c;
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  solve();
  return 0;
}

