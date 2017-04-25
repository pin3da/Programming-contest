// http://codeforces.com/contest/526/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

long long c, hr, hb, wr, wb;

/*
 *int dp[10000005];
 *long long go(long long cur) {
 *  if (dp[cur] != -1)
 *    return dp[cur];
 *  long long a = (cur + wr <= c) ? go(cur + wr) + hr : 0;
 *  long long b = (cur + wb <= c) ? go(cur + wb) + hb : 0;
 *  return dp[cur] = max(a, b);
 *}
 *
 */
const long long MN = 10000000;

int main() { ___
  cin >> c >> hr >> hb >> wr >> wb;
  //memset(dp, -1, sizeof dp);
  // cout << go(0) << endl;

  long long r = c / wr;
  long long b = c / wb;

  long long best = 0;
  for (int i = 0; i <= min(r, MN); ++i) {
    long long rr = r - i;
    best = max(best, rr * hr + ((c - (rr * wr)) / wb ) * hb);
  }

  for (int i = 0; i <= min(b, MN); ++i) {
    long long bb =  b - i;
    best = max(best, bb * hb + ((c - (bb * wb)) / wr) * hr);
  }

  cout << best << endl;
  return 0;
}
