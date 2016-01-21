#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


void add(string &line, vector<vector<int>> &next, int id, string mio) {
  if (id == line.size()) {
    if (mio.size())
      cout << mio << endl;
    return;
  }

  if (mio.size())
    cout << mio << endl;
  for (int i = 0; i < 26; ++i) {
    int to = next[i][id];
    if (to != line.size()) {
      mio.push_back('a' + i);
      add(line, next, to + 1, mio);
      mio.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    vector<vector<int>> next(26, vector<int> (line.size() + 1));

    for (int i = 0; i < 26; ++i) {
      next[i][line.size()] = line.size();
      for (int j = line.size() - 1; j >= 0; --j) {
        if (line[j] == 'a' + i) {
          next[i][j] = j;
        } else {
          next[i][j] = next[i][j + 1];
        }
      }
    }

    add(line, next, 0, "");
    cout << endl;
  }
  return 0;
}
