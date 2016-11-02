#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 10001;


int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  map<int, int> frec;

  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= j; ++k) {
        long long f = i * (j + k) + j * k;
        if (f >= MN) break;
        frec[f]++;
      }
    }
  }

  int n;
  while (cin >> n && n != -1) {
    cout << frec[n] << endl;
  }
  return 0;
}
