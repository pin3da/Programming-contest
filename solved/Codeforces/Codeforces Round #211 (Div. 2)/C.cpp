// http://codeforces.com/contest/363/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve(string &line) {
  string ans1;
  for (int i = 0; i < line.size(); ++i) {
    if (i < 2) ans1.push_back(line[i]);
    else {
      if (line[i] != ans1[ans1.size() - 1]
          || line[i] != ans1[ans1.size() - 2]) {
        ans1.push_back(line[i]);
      }
    }
  }

  // cout << ans1 << endl;
  if (ans1.size() <= 3) {
    cout << ans1 << endl;
    return;
  }
  string ans;
  for (int i = 0; i + 1 < ans1.size(); ++i) {
    if (i < 2) ans.push_back(ans1[i]);
    else {
      int cool = false;
      if (ans[ans.size() - 1] == ans[ans.size() - 2]
          && ans1[i] == ans1[i + 1]) {
        i++;
      } else if (i == ans1.size() - 2){
        cool = true;
      }
      ans.push_back(ans1[i]);
      if (cool)
        ans.push_back(ans1[i + 1]);
    }
  }
  cout << ans << endl;
}

int main() {
  string line;
  while (cin >> line) solve(line);
  return 0;
}
