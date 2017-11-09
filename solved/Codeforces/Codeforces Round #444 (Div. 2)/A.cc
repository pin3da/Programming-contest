#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line; cin >> line;
  int ans = 0;
  for (auto i : line) {
    ans += i == '0';
  }

  puts(ans > 5 ? "yes": "no");

  return 0;
}
