#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  char op; cin >> op;
  long double x, ans = 0;
  for (size_t i = 0; i < 12; ++i)
    for (size_t j = 0; j < 12; ++j) {
      cin >> x;
      if (j > i)
        ans += x;
    }

  if (op == 'M')
    ans /= (144.0 - 12) * 0.5;
  cout << ans << endl;
  return 0;
}
