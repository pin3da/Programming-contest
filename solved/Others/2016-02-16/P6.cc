#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, c;
  while (cin >> n >> c) {
    int  a = n / c;
    vector<int> t(c);
    for (int i = 0; i < c; ++i)
      cin >> t[i];

    int found = false;

    for (int p = t[0]; p < t[1] && !found; ++p) {
      int ok = true;
      int pos = p;

      for (int i = 0; i < c - 1; ++i) {
        if (t[i + 1] <= pos) {
          ok = false;
        }
        pos += a;
        if (t[i + 1] > pos)
          ok = false;
      }


      if (t[0] + n <= pos)
        ok = false;

      if (t[0] + n > pos + a)
        ok = false;

      if (ok)
        found  = true;
    }

    if (found)
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
