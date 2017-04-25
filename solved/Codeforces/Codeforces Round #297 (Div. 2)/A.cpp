// http://codeforces.com/contest/525/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> cur(30, 0);
    string line; cin >> line;
    int ans = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (i & 1) {
        if (!cur[line[i] - 'A'])
          ans++;
        else
          cur[line[i] - 'A']--;
      } else {
         cur[line[i] - 'a']++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

