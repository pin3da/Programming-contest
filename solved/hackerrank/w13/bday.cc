using namespace std;
#include<bits/stdc++.h>

void solve() {

  long long x,y,z, b, w;
  cin >> b >> w;
  cin >> x >> y >> z;
  cout << min(b * x + y * w, min((b + w) * x + z * w,(b + w) * y + z * b )) << endl;
}

int main() {

  int t; cin >> t;
  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}
