#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    vector<int> usa(3), russ(3);
    int ans = 0;
    int totu = 0, totr = 0;
    for (int i = 0; i < 3; ++i) {
      cin >> usa[i];
      if (i) cout << " ";
      cout << usa[i];
      totu += usa[i];
    }
    for (int i = 0; i < 3; ++i) {
      cin >> russ[i];
      cout << " ";
      cout << russ[i];
      totr += russ[i];
    }
    cout << endl;
    if (totu > totr)
      ans |= 1;

    if (usa > russ)
      ans |= 2;

    if (ans == 3)
      cout << "both" << endl;
    if (ans == 2)
      cout << "color" << endl;
    if (ans == 1)
      cout << "count" << endl;
    if (ans == 0)
      cout << "none" << endl;
  }
  return 0;
}
