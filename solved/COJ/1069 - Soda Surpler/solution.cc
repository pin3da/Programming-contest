#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int  a,b,c;
    cin >> a >> b >> c;
    if(c == 1) {
      cout << 0 << endl;
      continue;
    }
    a += b;
    int ans = 0;

    while(a >= c){
      ans += a / c;
      a = a / c + (a % c);
    }
    cout << ans << endl;
  }
  return 0;
}
