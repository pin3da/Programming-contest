#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

const int MN = 22;
const int MM = 2222;
int cost[MN][MM];
int t[MN];
int pref[MN][MM];
const int inf = 500000000;

int dp[MN][MM];
int col[MN][MM];
int curcol;

int N;
int go(int n, int k) {
  if (n == N) {
    if (k == 0) return 0;
    return -inf;
  }

  if (col[n][k] == curcol)
    return dp[n][k];

  col[n][k] = curcol;
  int op = go(n + 1, k);
  for (int i = 1; i <= t[n] && i <= k; ++i) {
    op = max(op, go(n + 1, k - i) + i * 10 - pref[n][i - 1]);
  }
  return dp[n][k] = op;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, k;
  curcol = 1;
  while (cin >> n >> k) {
    N = n;
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
      for (int j = 0; j < t[i]; ++j) {
        cin >> cost[i][j];
        pref[i][j] = cost[i][j];
        if (j)
          pref[i][j] += pref[i][j - 1];
      }
    }

    int best = -inf, id = - 1;
    for (int i = 0; i <= k; ++i) {
      int cur = go(0, i);
      if (cur > best) {
        best = cur;
        id = i;
      }
    }

    cout << best << " " << id << endl;

    int i = 0;
    while (i < n) {
      int op1 = go(i + 1, id);
      int op2 = -inf;
      int id_best = -1;
      for (int j = 1; j <= t[i] && j <= id; ++j) {
        int tt = go(i + 1, id - j) + j * 10 - pref[i][j - 1];
        if (tt > op2) {
          op2 = tt;
          id_best = id - j;
        }
      }
      if (op1 > op2) {
        if (i) cout << " ";
        i++;
        cout << 0;
        continue;
      }

      if (i) cout << " ";
      cout << id - id_best;
      i++;
      id = id_best;
    }
    cout << endl;

    curcol++;
  }

  return 0;
}

