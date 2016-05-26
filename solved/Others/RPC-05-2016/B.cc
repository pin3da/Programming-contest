#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int n,m, memo[MAXN];


int solve1(int c, int idx, vector<vector<int> > &B) {
  if(idx >= n) return 0;
  if(memo[idx] != -1) return memo[idx];
  int ans = solve1(c, idx + 1, B);
  ans = max(ans, solve1(c, idx + 2, B) + B[idx][c]);
  return memo[idx] = ans;

}

int solve2(int idx, vector<int> &v) {
  if(idx >= v.size()) return 0;
  if(memo[idx] != -1) return memo[idx];
  int ans = solve2(idx + 1, v);
  ans = max(ans, solve2(idx + 2, v) + v[idx]);

  return memo[idx] = ans;

}

int main() {
  while(cin >> n >> m) {
    vector<vector<int> > board(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) cin >> board[i][j];
    }

    vector<int> sol1(m);
    for(int i = 0; i < m; i++) {
      memset(memo, -1, sizeof memo);
      sol1[i] = solve1(i, 0, board);
    }
    memset(memo, -1, sizeof memo);
    int ans = solve2(0, sol1);
    cout << ans << endl;

  }
}
