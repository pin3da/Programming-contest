#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string line;
  while (cin >> line) {
    long long a = stoll(line);
    int ans = 0;
    while (line != "0") {
      string b = line;
      a = stoll(line);
      sort(b.begin(), b.end());
      long long nx = llabs(a - stoll(b));
      line = to_string(nx);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
