#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  char op;
  double total = 0, k;
  int t = 0;
  cin >> op;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cin >> k;
      if (i > 4) continue;
      if (j > i  && j < 11 - i) {
        total += k;
        t++;
      }
    }
  }

  if (op == 'M')
    total /= t;
  cout << fixed << setprecision(1) << total << endl;
  return 0;
}
