// http://codeforces.com/contest/801/problem/A

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int count(string line) {
  int ans = 0;
  for (int i = 0; i + 1 < (int)line.size(); ++i)
    if (line[i] == 'V' && line[i + 1] == 'K')
      ans++;

  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string line; cin >> line;
  int ans = count(line);
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == 'V') {
      line[i] = 'K';
      ans = max(ans, count(line));
      line[i] = 'V';
    } else {
      line[i] = 'V';
      ans = max(ans, count(line));
      line[i] = 'K';
    }
  }
  cout << ans << endl;

  return 0;
}
