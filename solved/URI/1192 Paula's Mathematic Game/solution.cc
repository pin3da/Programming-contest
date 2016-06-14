#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    string line; cin >> line;
    int a = line[0] - '0',
        b = line[2] - '0';
    if (a == b) {
      cout << a * b << endl;
      continue;
    }
    if (isupper(line[1]))
      cout << b - a << endl;
    else
      cout << a + b << endl;
  }
  return 0;
}
