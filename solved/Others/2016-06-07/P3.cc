#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

vector<string> br[] = {
  { ".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*" },
  { "**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*." },
  { "..", "..", "..", "..", "..", "..", "..", "..", "..", ".." }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int d;
  while (cin >> d && d) {
    char c; cin >> c;
    if (c == 'S') {
      string line; cin >> line;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < line.size(); ++j) {
          if (j) cout << ' ';
          cout << br[i][line[j] - '0'];
        }
        cout << endl;
      }
    } else {
      vector<vector<string>> cur(d, vector<string>(3));
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < d; ++j) {
          cin >> cur[j][i];
        }
      }

      for (int i = 0; i < d; ++i) {
        for (int j = 0; j < 10; ++j) {
          int ok = true;
          for (int k = 0; k < 3; ++k) {
            ok &= cur[i][k] == br[k][j];
          }
          if (ok) {
            cout << j;
            break;
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}
