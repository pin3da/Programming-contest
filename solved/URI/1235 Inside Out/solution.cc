#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  string line;
  getline(cin, line);
  while (tc--) {
    getline(cin, line);
    int mid = line.size() / 2;
    for (int i = mid - 1; i >= 0; --i)
      cout << line[i];
    for (int i = line.size() - 1; i >= mid; --i)
      cout << line[i];
    cout << endl;
  }
  return 0;
}
