#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string line; cin >> line;
  int ans = 0;
  for (int i = 0; i < line.size(); i++) {
    ans += line[i] - '0';
    ans %= 3;
  }
  cout << ans << endl;
  return 0;
}
