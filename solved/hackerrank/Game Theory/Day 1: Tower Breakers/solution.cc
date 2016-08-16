#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--) {
    int n, m; cin >> n >> m;
    if (n & 1)
      puts(m > 1 ? "1" : "2");
    else
      puts("2");
  }
  return 0;
}
