#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    vector<int> cur(10);
    int ans = 0;
    for (int i = 0; i < cur.size(); ++i) {
      cin >> cur[i];
      if (cur[i] == 17)
        ans |= 1;
      if (cur[i] == 18)
        ans |= 2;
      if (i) cout << " ";
      cout << cur[i];
    }
    cout << endl;

    if (ans == 3)
      cout << "both" << endl;
    if (ans == 1)
      cout << "zack" << endl;
    if (ans == 2)
      cout << "mack" << endl;
    if (ans == 0)
      cout << "none" << endl;
  }
  return 0;
}
