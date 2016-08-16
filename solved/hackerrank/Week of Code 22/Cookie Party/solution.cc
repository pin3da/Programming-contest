#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;
  while (cin >> m >> n) {
    if (n % m)
      cout << m - (n % m) << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
