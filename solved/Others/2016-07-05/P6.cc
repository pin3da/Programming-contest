#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b, c;
  while (cin >> a >> b >> c) {
    vector<int> frec(1000);
    for (auto &i : a) frec[i]++;
    for (auto &i : b) frec[i]++;
    for (auto &i : c) frec[i]--;
    int ok = true;
    for (auto &i : frec)
      ok &= (i == 0);
    puts(ok ? "YES" : "NO");
  }

  return 0;
}
