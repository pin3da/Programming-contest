// http://codeforces.com/contest/71/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string line; cin >> line;
    if (line.size() > 10) {
      cout << line[0] << line.size() - 2 << line[line.size() - 1] << endl;
    } else {
      cout << line << endl;
    }
  }
  return 0;
}
