#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  long long total = 0;
  cin >> n;
  while (n--) {
    long long t; cin >> t;
    total += t;
  }
  cout << (total + 4) / 5 << endl;
  return 0;
}
