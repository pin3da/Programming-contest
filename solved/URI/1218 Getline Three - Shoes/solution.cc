#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int tc = 0;
  while (getline(cin, line)) {
    string n = line;
    getline(cin, line);
    stringstream ss(line);
    string t;
    string m;
    vector<int> ans(2);
    while (ss >> t >> m) {
      if (t == n)
        ans[m == "M"]++;
    }
    if (tc != 0)
      cout << endl;
    cout << "Caso " << (++tc) << ":" << endl;
    cout << "Pares Iguais: " << ans[0] + ans[1] << endl;
    cout << "F: " << ans[0] << endl;
    cout << "M: " << ans[1] << endl;
  }
  return 0;
}
