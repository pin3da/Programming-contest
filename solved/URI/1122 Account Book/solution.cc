#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int BASE = 1000 * 40 + 100;


int dp[44][(BASE << 1) + 10];
int opt[44][2];

bool go(vector<int> &a, int i, int sum) {
  if (a.size() == i)
    return (sum == BASE);

  if (dp[i][sum] == -1) {
    int op1 = go(a, i + 1, sum + a[i]);
    int op2 = go(a, i + 1, sum - a[i]);
    if (op1)
      opt[i][0] = true;
    if (op2)
      opt[i][1] = true;
    dp[i][sum] = op1 || op2;
  }
  return dp[i][sum];
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, f;
  while (cin >> n >> f && (n + f)) {
    f += BASE;
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;
    memset(dp, -1, sizeof dp);
    memset(opt, 0, sizeof opt);
    int p = go(a, 0, f);
    if (p) {
      int cur = 0;
      int s = f;
      while (cur != a.size()) {
        if (opt[cur][0] && opt[cur][1])
          cout << "?";
        else if (opt[cur][0])
          cout << "-";
        else
          cout << "+";
        cur++;
      }
      cout << endl;
    } else {
      cout << "*" << endl;
    }
  }
  return 0;
}

