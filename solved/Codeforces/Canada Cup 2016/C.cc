#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

char ans[2][13];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  while (cin >> line) {
    int ok = true;
    vector<int> frec(30);
    frec[line[0] - 'A']++;
    for (int i = 1; i < (int)line.size(); ++i) {
      if (line[i] == line[i - 1])
        ok = false;
      frec[line[i] - 'A']++;
    }
    if (!ok) {
      cout << "Impossible" << endl;
      continue;
    }

    char A = 'A';
    for (int i = 0; i < (int)frec.size(); ++i) {
      if (frec[i] == 2) {
        A = i + 'A';
      }
    }
    int x = -1, y = - 1;
    for (int i = 0; i < (int)line.size(); ++i) {
      if (line[i] == A) {
        if (x == -1) x = i;
        else         y = i;
      }
    }

    memset(ans, -1, sizeof ans);

    int delta = (y - x - 1) / 2;
    int start = 12 - delta;
    int id = x;
    for (int i = start; i < 13; ++i) {
      ans[0][i] = line[id];
      id = (id + 1) % line.size();
    }
    for (int i = 12; i >= 0;) {
      if (line[id] != A) {
        ans[1][i] = line[id];
        i--;
      }
      id = (id + 1) % line.size();
    }
    for (int i = 0; i < start; ++i) {
      ans[0][i] = line[id];
      id = (id + 1) % line.size();
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 13; ++j) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
