#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, p;
  while (cin >> p >> n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int ok = true;
    for (int i = 1; i < n && ok; ++i) {
      if (abs(a[i - 1] - a[i]) > p)
        ok = false;
    }
    if (ok)
      cout << "YOU WIN" << endl;
    else
      cout << "GAME OVER" << endl;
  }
  return 0;
}
