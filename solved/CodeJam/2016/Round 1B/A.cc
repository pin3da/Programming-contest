#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ans[2000 + 20];

bool fs(string &line, int start, string &tar) {
  for (int i = 0; i < tar.size(); ++i) {
    int seen = 0;
    for (int j = start; j < line.size() && !seen; ++j) {
      if (line[j] == tar[i]) {
        swap(line[start], line[j]);
        seen = true;
        start++;
      }
    }
    if (!seen)
      return false;
  }
  return true;
}

bool solve(string &line, int id) {
  if (id == line.size())
    return true;

  for (int i = 0; i < 10; ++i) {
    if (fs(line, id, num[i]) && solve(line, id + num[i].size())) {
      ans[id] = i;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    string line; cin >> line;
    cout << "Case #" << (i + 1) << ": ";
    memset(ans, -1, sizeof ans);
    solve(line, 0);
    for (int i = 0; i < line.size(); ++i) {
      if (ans[i] != -1)
        cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
