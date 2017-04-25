// http://codeforces.com/contest/633/problem/A

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b, c;
  cin >> a >> b >> c;
  for (int x = 0; a * x <= c; x++) {
    int y = c - a * x;
    if ((y % b) == 0) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
