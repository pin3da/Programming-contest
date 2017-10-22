#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MX = 102;
unsigned long long bin[MX][MX];

void calc_bin() {
  for (int i = 0; i < MX; i++)
    for (int j = 0; j < MX; j++) bin[i][j] = 1;
  for (int i = 2; i < MX; i++) {
    for (int j = 1; j < i; j++) {
      bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  calc_bin();

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int y = 0, x = n;
    if (n < 2) {
      if (n == 1) cout << "x+y" << endl;
      else cout << "1" << endl;
      continue;
    }
    for (int i = 0; i < n + 1; i++) {
      if (bin[n][i] > 1) cout << bin[n][i];
      if (x) {
        cout << 'x';
        if (x > 1) cout << '^' << x;
      }
      if (y) {
        cout << 'y';
        if (y > 1) cout << '^' << y;
      }
      x--;y++;
      if (i + 1 < n + 1) cout << "+";
    }
    cout << endl;
  }

  return 0;
}
