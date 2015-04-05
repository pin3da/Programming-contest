using namespace std;
#include <bits/stdc++.h>
#define D(x)  cout << #x " = " << (x) << endl

const int MN = 22;

int base, k, n;
int p[MN][MN];
map<char, long long> dc;
long long dp[(1 << 17) + 17][MN];

long long go(const string &line, int mask, int mod) {
  if (mask == (1 << n) - 1)
    return mod == 0;

  if (dp[mask][mod] != -1)
    return dp[mask][mod];

  long long ans = 0;
  int exp = __builtin_popcount(mask);
  for (int i = 0; i < n; ++i) {
    if (!((mask >> i) & 1)) {
      ans += go(line, mask | (1 << i), (mod + (dc[line[i]] * p[base][exp]) ) % k);
    }
  }
  return dp[mask][mod] = ans;
}

void solve() {
  scanf("%d%d", &base, &k);
  for (int i = 0; i < MN; ++i) {
    p[i][0] = 1;
    for (int j = 1; j < MN; ++j)
      p[i][j] = (p[i][j - 1] * (long long)i) % k;
  }
  string line;
  cin >> line;
  n = line.size();
  memset(dp, -1, sizeof dp);
  reverse(line.begin(), line.end());
  printf("%lld\n", go(line, 0, 0));
}

int main() {


  string asdf = "0123456789ABCDEF";
  for (int i = 0; i < asdf.size(); ++i)
    dc[asdf[i]] =  i;


  int n;
  scanf("%d", &n);
  for (int tc = 0; tc < n; ++tc) {
    printf("Case %d: ", tc + 1);
    solve();
  }
  return 0;
}
