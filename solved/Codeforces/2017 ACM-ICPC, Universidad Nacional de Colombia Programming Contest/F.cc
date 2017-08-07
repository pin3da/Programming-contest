#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  int ok = true;
  for (int i = 0; i < n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> len = {a, b, c};
    sort(len.begin(), len.end());
    ok &= (len[2] < (len[1] + len[0]));
  }

  puts(ok ? "YES" : "NO");

  return 0;
}
