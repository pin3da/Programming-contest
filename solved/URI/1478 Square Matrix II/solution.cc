#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j) cout << ' ';
        cout << right << setw(3) << abs(i - j) + 1;
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
