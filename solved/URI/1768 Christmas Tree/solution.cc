#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    int levels = (n + 1) >> 1;
    for (int i = 0, t = 1; i < levels; ++i, t += 2) {
      cout << string(levels - 1 - i, ' ');
      cout << string(t, '*');
      cout << endl;
    }
    cout << string(levels - 2, ' ') << " *" << endl;
    cout << string(levels - 2, ' ') << "***" << endl << endl;
  }
  return 0;
}
