// http://codeforces.com/contest/452/problem/A

using namespace std;
#include <bits/stdc++.h>

string p[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};


int main() {
  int s;
  while (cin >> s) {
    string line; cin >> line;
    for (int i = 0; i < 8; ++i) {
      if (line.size() != p[i].size()) continue;
      int ok = 1;
      for (int j = 0; j < line.size() && ok; ++j)
        if (line[j] != '.' && line[j] != p[i][j])
          ok = false;

      if (ok) {
        cout << p[i] << endl;
        break;
      }
    }
  }
  return 0;
}
