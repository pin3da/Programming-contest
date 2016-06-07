#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  string line; getline(cin, line);
  while (tc--) {
    getline(cin, line);
    stringstream ss(line);
    while (ss >> line) {
      cout << line[0];
    }
    cout << endl;
  }

  return 0;
}
