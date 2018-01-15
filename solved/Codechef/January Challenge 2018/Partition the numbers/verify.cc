#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  string line;
  int cid = 0;
  while (cin >> line) {
    if (line == "impossible") {
      cout << cid << endl;
      assert(false);
    }
    vector<int> ans(3);
    for (int i = 0; i < (int)line.size(); i++) {
      ans[line[i] - '0'] += (i + 1);
    }
    if (argc == 1)
      assert(ans[0] == ans[1]);
    else {
      if (ans[0] != ans[1])
        cout << cid << endl;
    }
    cid++;
  }
  return 0;
}
