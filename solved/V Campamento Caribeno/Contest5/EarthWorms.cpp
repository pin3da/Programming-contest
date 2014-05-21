using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x)<<endl

vector<pair<int, int> > g[22];

const int inf = 1<<30;
string line;

int memo[55][55][22];

int dp(int i, int j, int c) {
  if (i == j)
    return (c == (line[i] - 'A')) ? 0 : inf;

  if (memo [i][j][c] != -1) return memo[i][j][c];

  int ans = inf;
  for (int k = i; k < j; ++k) {
    for (int r = 0; r < g[c].size(); ++r) {
      int o1 = dp(i, k, g[c][r].first);
      int o2 = dp(k + 1, j, g[c][r].second);
      if (o1 == inf or o2 == inf) continue;
      ans = min(ans, max(o1, o2) + 1);
    }
  }
  //cout<<"dp from "<<i<<" to "<<j<<" with c"<<ans<<endl;
  return memo[i][j][c] = ans;
}

int main() { ___

  int n;
  while (cin>>n and n) {
    string rule;
    for (int i = 0 ; i < 20; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      cin>>rule;
      g[rule[0] - 'A'].push_back(make_pair(rule[1] - 'A', rule[2] - 'A'));
    }
    cin>>line;

    int ans = 1<<30;
    memset(memo, -1, sizeof memo);
    for (int c = 0 ; c < 20; ++c)
      ans = min(ans , dp(0, line.size() - 1, c));

    if (ans == inf)
      cout<<-1<<endl;
    else
     cout<<ans<<endl;
  }

  return 0;
}
