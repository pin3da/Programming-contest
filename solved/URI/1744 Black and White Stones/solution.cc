#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int A, B;
const int MN = 5000 + 10;
int w[MN], b[MN];

int get_w(int i, int j) {
  return w[j + 1] - w[i];
}

int tot_b;
long long dp[MN][MN];

long long go(int j, int k) {
  int i = tot_b - (k - j + 1);
  if (i == tot_b) return 0;

  if (dp[j][k] != -1)
    return dp[j][k];

  int s = tot_b - k - 1;
  if (b[j] == i) return dp[j][k] = go(j + 1, k);
  long long op1 = go(j + 1, k) + (get_w(0, b[j]) - s) * (A - B);
  long long extra = A;
  if (b[k] == i + 1) extra -= B;
  long long op2 = go(j, k - 1) + extra;
  return dp[j][k] = min(op1, op2);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  while (cin >> A >> B) {
    string line;
    cin >> line;
    w[0] = 0;
    int b_id = 0;
    for (int i = 0; i < (int)line.size(); ++i) {
      w[i + 1] = (line[i] == 'W') + w[i];
      if (line[i] == 'B')
        b[b_id++] = i;
    }
    tot_b = line.size() - w[line.size()];
    memset(dp, -1, sizeof dp);
    cout << go(0, tot_b - 1) << endl;
  }
  return 0;
}
