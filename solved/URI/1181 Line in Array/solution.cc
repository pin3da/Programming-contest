#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x;
  double total = 0, t;
  cin >> x;
  char op;
  cin >> op;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cin >> t;
      if (i == x)
        total += t;
    }
  }
  cout << fixed << setprecision(1) << (op == 'S' ? total : total / 12.0) << endl;
  return 0;
}
