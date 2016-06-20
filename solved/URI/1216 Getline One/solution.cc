#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  double ans = 0, t = 0;
  cout << setprecision(1) << fixed;
  while (getline(cin, line)) {
    getline(cin, line);
    stringstream ss(line);
    double m; ss >> m;
    ans += m;
    t++;
  }
  cout << (ans / t) << endl;
  return 0;
}
