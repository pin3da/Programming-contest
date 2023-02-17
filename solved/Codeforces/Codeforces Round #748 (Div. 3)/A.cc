#include <bits/stdc++.h>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int mmax = max(max(a, b), c);
    int num_winners = 0;
    if (a == mmax) num_winners++;
    if (b == mmax) num_winners++;
    if (c == mmax) num_winners++;
    auto best = [&](int x) -> int {
      if (x == mmax) return (num_winners == 1) ? 0 : 1;
      int left = mmax - x;
      return left + 1;
    };
    cout << best(a) << " " << best(b) << " " << best(c) << endl;
  }
  return 0;
}