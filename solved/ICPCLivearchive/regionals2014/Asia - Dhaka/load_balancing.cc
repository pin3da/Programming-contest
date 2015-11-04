using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long inf = 1LL << 50;

long long dp[166][4];

long long go(int i, int k, vector<long long> &frec, const int &n) {
  if (i == frec.size()) {
    if (k == 0) return 0;
    return inf;
  }

  if (k == 0) return inf;

  if (dp[i][k] != -1)
    return dp[i][k];


  long long best = inf;
  for (int j = i; j < frec.size(); ++j) {
    long long cur = 4 * frec[j] - 4 * (i? frec[i - 1] : 0);
    cur = llabs(cur - n);
    best = min(best, cur + go(j + 1, k - 1, frec, n));
  }
  return dp[i][k] = best;
}

void solve() {
  int n; cin >> n;
  vector<long long> frec(161);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    frec[t]++;
  }

  for (int i = 1; i < frec.size(); ++i)
    frec[i] += frec[i - 1];

  memset(dp, -1, sizeof dp);

  // cout <<  go(0, 4, frec, n) << endl;
  int i = 0, k = 4;
  while (k > 1) {
    for (int j = i; j < frec.size(); ++j) {
      long long cur = 4 * frec[j] - 4 * (i? frec[i - 1] : 0);
      cur = llabs(cur - n) + go(j + 1, k - 1, frec, n);
      if (cur == go(i, k, frec, n)) {
        printf(" %d", j);
        i = j + 1;
        k--;
        break;
      }
    }
  }
  puts("");
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:", i + 1);
    solve();
  }
  return 0;
}
