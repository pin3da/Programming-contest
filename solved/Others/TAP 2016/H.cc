#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
int N, X, Y;

typedef long double T;
const int MN = 1234;
T dp[MN][MN];
int col[MN][MN];
int curcol;

T go(int r, int m) {
  T may = m;
  T total = N - r + 1;
  T men = total - may - 1;

  if (total == 1) return r == Y;
  if (r == Y) {
    return (1.0 / total) * (may / (total - 1)) + (may / (total)) * (1 / (total - 1));
  }

  if (col[r][m] == curcol) return dp[r][m];

  T op1 = 0;
  if (may >= 2)
    op1 = (may / (total)) * (may - 1) / (total - 1) *
      go(r + 1, m - 1); // mayor-mayor

  T op2 = ((may + 1) / total) *
    (men / (total - 1)) * go(r + 1, m);
  // mayor - menor, me incluyo en los mayores

  T op4 = (men / (total)) * ((may + 1) / (total - 1)) * go(r + 1, m);
  T op3 = 0;
  if (men >= 2)
    op3 = ((men) / total) * ((men - 1) / (total - 1))
      * go(r + 1, m); // menor -menor
  col[r][m] = curcol;
  return dp[r][m] = (op1 + op3 + op2 + op4);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(4);
  while (cin >> N >> X >> Y) {
    curcol++;
    Y = N - Y + 1;
    cout << go(1, X - 1) + 1e-9 << endl;
  }
  return 0;
}
