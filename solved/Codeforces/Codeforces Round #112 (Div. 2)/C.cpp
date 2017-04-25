// http://codeforces.com/contest/165/problem/C

using namespace std;
#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(int k) {
  string line;
  cin >> line;
  if (k == 0) {
    long long ans = 0;
    for (int i = 0; i < line.size(); ++i) if (line[i] == '1') line[i] = ' ';
    stringstream ss(line);
    while (ss >> line) {
      long long t = line.size();
      ans += (t * (t + 1)) >> 1;
    }
    cout << ans << endl;
    return;
  }

  vector<int> ps(line.size());
  ps[0] = line[0] == '1';
  for (int i = 1; i < line.size(); ++i)
    ps[i] = ps[i - 1] + (line[i] == '1');

  long long ans = 0;
  for (int i = 0; i < line.size(); ++i) {
    int a = ps[i],
        b = ps[i] + k;
    b -= (line[i] == '1');
    auto it = lower_bound(ps.begin(), ps.end(), b);
    if (it == ps.end()) continue;
    auto it2 =  upper_bound(ps.begin(), ps.end(), b);
    it2--;
    ans += it2 - it + 1;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int k;
  while (cin >> k) solve(k);
  return 0;
}
