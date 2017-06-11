#include <bits/stdc++.h>

using namespace std;

int ans[] = {56, 96, 36, 76, 16};

void solve() {
  string line; cin >> line;
  if (line.size() < 2) {
    int e = stoi(line);
    int ans = 1;
    while (e--) {
      ans = (ans * 66) % 100;
    } 
    cout << ans << endl;
    return;
  }
  int mod = 5;
  int exp = 0;
  for (int i = 0; i < (int)line.size(); ++i) {
    exp = (exp * 10) % mod;
    exp = (exp + (line[i] - '0')) % mod; 
  }
  exp = (exp - 2 + mod) % mod;
  cout << ans[exp] << endl; 
}

int main() {
  int tc; cin >> tc;
  while (tc--) 
    solve();
  return 0;
}
