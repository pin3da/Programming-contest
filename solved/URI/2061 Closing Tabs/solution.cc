#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    while (m--) {
      string line; cin >> line;
      if (line[0] == 'f')
        n++;
      else
        n--;
    }
    cout << n << endl;
  }

  return 0;
}
