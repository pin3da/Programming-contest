#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; string line;
    cin >> n >> line;
    int empty = line.find("_") != string::npos;
    if (empty)
      sort(line.begin(), line.end());

    vector<int> ok(line.size());
    for (int i = 0; i < (int)line.size(); ++i) {
      if (i - 1 >= 0) ok[i] = line[i] == line[i - 1];
      if (i + 1 < (int)line.size()) ok[i] |= (line[i] == line[i + 1]);
    }
    int allok = true;
    for (int i = 0; i < (int)line.size(); ++i) {
      if (line[i] != '_') allok &= ok[i];
    }
    puts(allok ? "YES" : "NO");
  }
  return 0;
}
