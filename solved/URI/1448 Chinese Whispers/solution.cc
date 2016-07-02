#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  string line; getline(cin, line);
  int id = 1;
  while (tc--) {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    int ans1 = 0, ans2 = 0, f1 = -1, f2 = -1;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) ans1++;
      if (a[i] == c[i]) ans2++;
      if (a[i] == b[i] && a[i] != c[i] && f1 == -1) f1 = i;
      if (a[i] == c[i] && a[i] != b[i] && f2 == -1) f2 = i;
    }
    cout << "Instancia " << id++ << endl;
    if (ans1 > ans2) {
      cout << "time 1" << endl;
    } else if (ans2 > ans1) {
      cout << "time 2" << endl;
    } else {
      if (f1 < f2)
        cout << "time 1" << endl;
      else if (f2 < f1)
        cout << "time 2" << endl;
      else
        cout << "empate" << endl;
    }
    cout << endl;
  }

  return 0;
}
