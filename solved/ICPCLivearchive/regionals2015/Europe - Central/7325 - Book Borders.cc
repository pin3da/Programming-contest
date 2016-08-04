#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    string buff; getline(cin, buff);
    stringstream ss(buff);
    int a, b;
    ss >> a >> b;
    vector<int> next(line.size());
    vector<int> len(line.size());
    next[0] = 0;
    for (int i = 1; i < line.size(); ++i) {
      if (line[i - 1] == ' ') next[i] = i;
      else if (line[i] == ' ') {
        next[i] = i + 1;
        len[next[i - 1]] = i - next[i - 1];
      }
      else next[i] = next[i - 1];
    }

    len[next[line.size() - 1]] = line.size() - next[line.size() - 1];
    /*
    for (int i = 0; i < line.size(); ++i) {
      cout << i << " " << line[i] << ": " << len[i] << " , " << next[i] << endl;
    }
    */

    for (int i = a; i <= b; ++i) {
      int total = 0;
      int j = 0;
      while (j < line.size()) {
        total += len[j] + 1;
        if (j + i >= line.size()) break;
        j = next[j + i];
      }
      cout << total - 1 << endl;
    }
  }

  return 0;
}
