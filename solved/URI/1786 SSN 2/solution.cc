#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    int b1 = 0, b2 = 0;
    for (int i = 0; i < line.size(); ++i) {
      int cur = line[i] - '0';
      b1 += cur * (i + 1);
      b2 += cur * (9 - i);
    }
    b1 %= 11; b1 %= 10;
    b2 %= 11; b2 %= 10;
    cout << line.substr(0, 3) << "." << line.substr(3, 3);
    cout << "." << line.substr(6, 3) << "-" << b1 << b2 << endl;
  }
  return 0;
}
