#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    char ant = '$';
    int frec = 0, ans = 0;
    while (ss >> line) {
      char cur = tolower(line[0]);
      if (cur == ant) {
        frec++;
      } else {
        ant = cur;
        if (frec) ans++;
        frec = 0;
      }
    }
    if (frec) ans++;
    cout << ans << endl;
  }
  return 0;
}
