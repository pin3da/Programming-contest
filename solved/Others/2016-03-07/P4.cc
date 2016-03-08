#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    while (n--) {
      vector<int> a(5);
      int last = -1;
      for (int i = 0; i < 5; ++i) {
        cin >> a[i];
        if (a[i] <= 127) {
          if (last == -1)
            last = i;
          else
            last = 100;
        }
      }
      if (last >= 0 && last < 5)
        cout << char(last + 'A') << endl;
      else
        cout << '*' << endl;
    }
  }
  return 0;
}
