#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double t;
  cin >> t;
  for (int i = 0; i < 100; ++i) {
    printf("N[%d] = %.4lf\n", i, t);
    t *= 0.5;
  }
  return 0;
}
