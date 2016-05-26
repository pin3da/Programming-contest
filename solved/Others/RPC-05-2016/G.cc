#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
typedef long long ll;

map<pair<int,int>, int > prices[MAXN];
int n,m,p, mxt;
int mx[] = {0, 1, 0, -1, 0};
int my[] = {0, 0, 1, 0, -1};
int memo[25][25][MAXN];

int solve(int x, int y, int tim) {
  if(tim > mxt) return 0;
  if(memo[x][y][tim] != -1) return memo[x][y][tim];
  int ans = solve(x, y, tim + 1);



  for(int i = 0; i < 5; i++) {
    int tx = x + mx[i];
    int ty = y + my[i];
    if(tx > 0 && tx <= n && ty > 0 && ty <= m){
      int toadd = 0;
      if(prices[tim + 1].count(make_pair(tx, ty))){
        toadd = prices[tim + 1][make_pair(tx, ty)];
      }
      ans = max(ans, solve(tx, ty, tim + 1) + toadd);
    }
  }
  return memo[x][y][tim] = ans;
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n >> m >> p;
    int x, y, xt, yt, tim, v; cin >> x >> y;

    memset(memo, -1, sizeof memo);
    for(int i = 0; i < MAXN; i++) prices[i].clear();

    for(int i = 0; i < p; i++) {
      cin >> xt >> yt >> tim >> v;
      prices[tim][make_pair(xt,yt)] = v;
    }
    mxt = p * 2 + 5;
    cout << solve(x, y, 0) << endl;

  }
}
