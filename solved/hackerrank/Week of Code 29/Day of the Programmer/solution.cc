#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve(vector<int> days, int n) {
  int t = 256;
  for (int i = 0; t > 0 && i < (int)days.size(); ++i) {
    if (t > days[i]) {
      t -= days[i];
      continue;
    }
    printf("%.2d.%.2d.%.4d\n", t, i + 1, n);
    return;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<int> days({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
  if (n < 1918) {
    if ((n & 3) == 0)
      days[1] = 29;
  } else if (n > 1918) {
    if ((n % 400) == 0 || ((n % 4) == 0  && (n % 100)))
        days[1] = 29;
  } else {
    days[1] = 15;
  }

  solve(days, n);
  return 0;
}
