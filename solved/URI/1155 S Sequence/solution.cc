#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double s = 0;
  for (int i = 1; i < 101; ++i)
    s += 1.0 / (double)i;
  cout << fixed << setprecision(2) << s << endl;
  return 0;
}
