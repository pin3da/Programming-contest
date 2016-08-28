#include<bits/stdc++.h>
using namespace std;
const int MX = 10;
const int MN = 250;

int n, arr[MX];
long long memo[MX][MN];

long long solve(int idx, int tmp){ 
  if(idx == 8) {
    return tmp == n;
  }
  if(memo[idx][tmp] != -1) return memo[idx][tmp];
  long long ans = solve(idx + 1, tmp);
  for(int i = 1; tmp + arr[idx] * i <= n; i++) {
    ans += solve(idx + 1, tmp + arr[idx] * i);
  }
  return memo[idx][tmp] = ans;
}

int main() {
  int t, nc = 0; cin >> t;
  while(t--) {
    for(int i = 0; i < 8; i++) cin >> arr[i];
    cin >> n;
    memset(memo, -1, sizeof memo);
    cout << "Equation #" << ++nc << ": " << solve(0, 0) << endl;
  }
}
