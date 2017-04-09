#include <bits/stdc++.h>

using namespace std;

bool flip(string &s, int i, int k) {
  if (i + k > (int)s.size())
    return false;

  for (int j = 0; j < k; ++j) {
    if (s[i + j] == '+')
      s[i + j] = '-';
    else
      s[i + j] = '+';
  }
  return true;
}

void solve() {
  string line;
  int k;
  cin >> line >> k;
  int ans = 0;
  for (int i = 0; i < (int)line.size(); ++i) {
    if (line[i] == '-') {
      if (!flip(line, i, k)) {
        puts("IMPOSSIBLE");
        return;
      }
      ans++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
