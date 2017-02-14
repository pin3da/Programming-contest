#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> frec(30);
  string cad; cin >> cad;

  for (char i : cad)
    frec[i - 'a']++;

  sort(frec.rbegin(), frec.rend());
  int ans = accumulate(frec.begin() + 2, frec.end(), 0);
  cout << ans << endl;
}
