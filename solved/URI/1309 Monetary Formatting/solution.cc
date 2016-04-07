#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string a, b;
  while (cin >> a >> b) {
    string c;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
      if ((i % 3) == 0 && i) {
        c.push_back(',');
      }
      c.push_back(a[i]);
    }
    reverse(c.begin(), c.end());
    cout << "$" << c << '.';
    if (b.size() < 2) cout << '0';
    cout << b << endl;
  }
  return 0;
}
