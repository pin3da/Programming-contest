#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  string a, b;
  while (tc--) {
    cin >> a >> b;
    int i;
    for (i = 0; i < min(a.size(), b.size()); ++i) {
      cout << a[i] << b[i];
    }
    if (i < a.size())
      cout << a.substr(i) << endl;
    else
      cout << b.substr(i) << endl;
  }

  return 0;
}
