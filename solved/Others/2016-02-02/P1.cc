#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
int N, C;

long long dp[200000 + 10][3];
int seen[200000 + 10][3];

long long go(vector<long long> &a, int id, int open) {
  if (id >= a.size())
    return 0;

  if (seen[id][open])
    return dp[id][open];

  seen[id][open] = 1;
  long long ans = go(a, id + 1, open);
  if (open)
    ans = max(ans, go(a, id + 1, 0) + a[id]);
  else
    ans = max(ans, go(a, id + 1, 1) - a[id] - C);
  return dp[id][open] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cin >> N >> C;
  vector<long long> a(N);
  for (auto &i : a)
    cin >> i;

  cout << go(a, 0, 0) << endl;
  return 0;
}
