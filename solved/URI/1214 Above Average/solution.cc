#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int c; cin >> c;
  cout << fixed << setprecision(3);
  while (c--) {
    int n; cin >> n;
    vector<double> a(n);
    double total = 0;
    for (auto &i : a) {
      cin >> i;
      total += i;
    }
    total /= n;
    double above = 0;
    for (auto &i : a)
      if (i > total)
        above++;

    above *= 100;
    cout << above / (double)n << '%' << endl;
  }

  return 0;
}
