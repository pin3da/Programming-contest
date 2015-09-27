using namespace std;
#include <bits/stdc++.h>
#define D(x)  cout << #x " = " << (x) << endl

int n;
string a, b;

const long long inf = 7000007;

map<char, char> comp;

long long dp[1111][1111][3];

long long go(int k, int i, int op) {
  if (k == n) return 0;

  if (dp[k][i][op] != -1)
    return dp[k][i][op];

  int j = n - 1 - (k - i);
  long long one = inf;
  if (a[i] == b[k]) {
    one = go(k + 1, i + 1, 0) + (op != 0);
  }


  long long two = inf;
  if (comp[a[j]] == b[k]) {
    two = go(k + 1, i, 1) + (op != 1);
  }

  return dp[k][i][op] = min(one, two);
}

int main() {
  comp['o'] = 'o';
  comp['v'] = 'v';
  comp['w'] = 'w';
  comp['x'] = 'x';
  comp['b'] = 'd';
  comp['d'] = 'b';
  comp['p'] = 'q';
  comp['q'] = 'p';

  cin >> n;
  cin >> a >> b;

  memset(dp, -1, sizeof dp);

  long long ans =  go(0, 0, 0);
  if (ans >= inf) {
    cout << -1 << endl;
  } else
    cout << ans << endl;

  return 0;
}
