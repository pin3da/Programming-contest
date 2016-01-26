#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double t;
  for (int i = 0; i < 100; ++i) {
    cin >> t;
    if (t <= 10)
      printf("A[%d] = %.1lf\n", i, t);
  }
  return 0;
}
