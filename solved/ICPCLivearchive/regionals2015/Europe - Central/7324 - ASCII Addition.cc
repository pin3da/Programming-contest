#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string dig[7][11] = {
  "xxxxx" , "....x","xxxxx","xxxxx", "x...x", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx", ".....",
  "x...x",  "....x","....x","....x", "x...x", "x....", "x....", "....x", "x...x", "x...x", "..x..",
  "x...x",  "....x","....x","....x", "x...x", "x....", "x....", "....x", "x...x", "x...x", "..x..",
  "x...x",  "....x","xxxxx","xxxxx", "xxxxx", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", "xxxxx",
  "x...x",  "....x","x....","....x", "....x", "....x", "x...x", "....x", "x...x", "....x", "..x..",
  "x...x",  "....x","x....","....x", "....x", "....x", "x...x", "....x", "x...x", "....x", "..x..",
  "xxxxx",  "....x","xxxxx","xxxxx", "....x", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", "....."
};

string line[7];

bool match(int col, int targ) {
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (line[i][j + col] != dig[i][targ][j]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> line[0]) {
    for (int i = 1; i < 7; ++i) cin >> line[i];

    long long a = 0, b = 0;
    int plus = false;
    for (int j = 0; j < line[0].size(); j += 6) {
      int cur  = 0;
      for (int i = 0; i < 11; ++i) {
        if (match(j, i)) {
           cur = i; break;
        }
      }

      if (!plus) {
        if (cur < 10) {
          a = a * 10 + cur;
        } else {
          plus = true;
        }
      } else {
        b = b * 10 + cur;
      }
    }

    deque<int> ans;
    long long c = a + b;
    while (c > 0) {
      ans.push_front(c % 10);
      c /= 10;
    }

    for (int j = 0; j < 7; ++j) {
      for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << ".";
        for (int k = 0; k < 5; ++k) {
          cout << dig[j][ans[i]][k];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
