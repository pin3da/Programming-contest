using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 2002;
const int MK = 22;
int dp[MN][MK];
int pref[MN];
int n;

const int inf = 1 << 30;

int fun(int i, int j) {
  int ans =  pref[j];
  if (i)
    ans -= pref[i - 1];
  ans = (ans + 5) / 10;
  return ans * 10;
}

int go(int id, int d) {
  if (id == n)
    return 0;

  if (d == 0) {
    return fun(id, n - 1);
  }

  if (dp[id][d] != -1)
    return dp[id][d];

  int best = inf;
  for (int j = id; j < n; ++j) {
      best = min(best, go(j + 1, d - 1) + fun(id, j));
  }

  return dp[id][d] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int d;
  while (cin >> n >> d) {
    for (int i = 0; i < n; ++i) {
      cin >> pref[i];
    }
    for (int i = 1; i < n; ++i) {
      pref[i] += pref[i - 1];
    }

    memset(dp, -1, sizeof dp);
    cout << go(0, d) << endl;
  }
  return 0;
}
