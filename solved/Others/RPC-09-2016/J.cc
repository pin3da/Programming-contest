#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MX = 505;

int memo[MX][MX], arr[MX], n;

int solve(int idx, int hm) {
  if(idx == n) return 0;
  if(memo[idx][hm] != -1) return memo[idx][hm];
  int ans = solve(idx + 1, hm);
  if(idx == 0) {
    ans = max(ans, solve(idx + 1, hm + 1) + arr[idx]);
  }
  else if(hm + 1 <= (idx + 1) >> 1) {
    ans = max(ans, solve(idx + 1, hm + 1) + arr[idx]);
  }
  return memo[idx][hm] = ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, nc = 0; cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(memo, -1, sizeof memo);
    cout << "Spree #" << ++nc << ": " << solve(0, 0) << endl;
  }
}
