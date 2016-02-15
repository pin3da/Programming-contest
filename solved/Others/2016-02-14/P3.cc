#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    /*if ((x & 1) == 0) {
      cout << "Not Prime" << endl;
      continue;
    }*/
    int ok = true;
    for (long long i = 2; (i * i) <= x && ok; ++i) {
      if ((x % i) == 0)
        ok = false;
    }
    if (!ok)
      cout << "Not ";
    cout << "Prime" << endl;
  }
  return 0;
}
