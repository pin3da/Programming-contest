using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<char> board(n);
  for (int i = 0; i < n; ++i)
    cin >> board[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (board[i] == '.') {
      ans++;
      i += 2;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
