#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double t, ans = 0;
  char a;
  cin >> a;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cin >> t;
      if (i <= 5 && j > 11 - i)
        ans += t;
      if (i >= 6 && j > i)
        ans += t;
    }
  }
  if (a == 'S')
    cout << fixed << setprecision(1) << ans << endl;
  else
    cout << fixed << setprecision(1) << ans / 30 << endl;

  return 0;
}

