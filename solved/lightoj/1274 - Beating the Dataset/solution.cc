using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN  = 5005;
double dp[2][MN][2];

void fill_dp(set<pair<int, int> > &queries, map<pair<int,int>, double > &answers) {
  memset(dp, 0, sizeof dp);
  int cur = 1, prev = 0;
  for (int n = 1; n < MN; ++n) {
    memset(dp[cur], 0, sizeof dp[cur]);
    for (int y = 0; y <= n; ++y) {
      double p_no  = (n - y) / (double) n;
      double p_yes = y / (double) n;
      for (int a = 0; a < 2; ++a) {
        if (y < n)
          dp[cur][y][a] += (dp[prev][y][0] + (a != 0)) * p_no;
        if (y > 0)
          dp[cur][y][a] += (dp[prev][y - 1][1] + (a != 1)) * p_yes;
      }
      if (queries.count(make_pair(n, y)))
        answers[make_pair(n, y)] = dp[cur][y][1];
    }
    swap(cur, prev);
  }
}


void read_in(set<pair<int, int> > &queries, vector<pair<int, int> > &order) {
  int n, m;
  cin >> n >> m;
  int y = m - n - n;
  queries.insert(make_pair(n, y));
  order.push_back(make_pair(n, y));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;

  set<pair<int, int> > queries;
  vector<pair<int, int> > order;
  for (int i = 0; i < tc; ++i)
    read_in(queries, order);

  map<pair<int, int>, double> answers;
  fill_dp(queries, answers);

  for (int i = 0; i < tc; ++i)
    printf("Case %d: %.10lf\n", i + 1, answers[order[i]]);


  return 0;
}
