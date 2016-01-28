#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x;
  while (cin >> x && x > 0) {
    for (long long i = 1; i <= x; ++i) {
      if (i > 1) cout << " ";
      cout << i;
    }
    cout << endl;
  }
  return 0;
}
