#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int inf = 1000000;

int add(int x, int y) {
  return min(inf, x + y);
}


int dp[111][1001];

int go(vector<int> &ener, vector<int> &cost, int i, int q) {
  if (i == ener.size()) {
    return 0;
  }

  if (dp[i][q] != -1)
    return dp[i][q];

  int op1 = add(go(ener, cost, i + 1, q), cost[i]);
  if (q >= ener[i]) {
    op1 = min(op1, go(ener, cost, i + 1, q - ener[i]));
  }
  return dp[i][q] = op1;
}

void solve() {
  int n, q, x;
  cin >> n >> q >> x;
  vector<int> energy(n), cost(n);
  for (int i = 0; i < n; ++i)
    cin >> energy[i];

  for (int i = 0; i < n; ++i)
    cin >> cost[i];

  memset(dp, -1, sizeof dp);
  int mincost = go(energy, cost, 0, q);
  if (mincost <= x) {
    cout << "Yes-Man" << endl;
  } else {
    cout << "No-Man" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
