#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  string m[] = {"A porta fechou!", "A porta abriu!"};
  for (int i = 0; i < n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    printf("%02d:%02d - %s\n", a, b, m[c].c_str());
  }
  return 0;
}

