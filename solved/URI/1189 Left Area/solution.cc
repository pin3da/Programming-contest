#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double t, ans = 0;
  char op;
  cin >> op;
  for (int i = 0; i < 12; ++i)
    for (int j = 0; j < 12; ++j) {
      cin >> t;
      if (i < 6 && (j < i))
        ans += t;
      else if (i > 5 && j < (11 - i))
        ans += t;
    }

  if (op == 'S')
    cout << fixed << setprecision(1) << ans << endl;
  else
    cout << fixed << setprecision(1) << ans / 30.0  << endl;
  return 0;
}

