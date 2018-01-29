#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

long long process(string line) {
  long long ans = 0;
  int n = line.size();
  for (int i = 0; i < n; i++) {
    int lo = 0, hi = 0;
    for (int j = i; j < n; j++) {
      if (line[j] == '(') {
        lo++;
        hi++;
      }
      if (line[j] == ')') {
        lo--;
        if (lo < 0) lo += 2;
        hi--;
        if (hi < 0) break;
      }
      if (line[j] == '?') {
        lo--;
        if (lo < 0) lo += 2;
        hi++;
      }
      if (lo == 0) ans++;
    }
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  set<pair<int, int>> seen;
  long long ans = process(line);
  cout << ans << endl;
  return 0;
}
