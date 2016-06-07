#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    int a = 0, b = 0;
    for (auto &i : line) {
      if (i == '_') {
        if (a & 1) cout << "</i>";
        else       cout << "<i>";
        a ^= 1;
      } else if (i == '*') {
        if (b & 1) cout << "</b>";
        else       cout << "<b>";
        b ^= 1;
      } else {
        cout << i;
      }
    }
    cout << endl;
  }

  return 0;
}
