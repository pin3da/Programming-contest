
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  map<char, int> ans;
  ans['A'] = 1;
  ans['B'] = 2;
  ans['O'] = 1;
  ans['P'] = 1;
  ans['D'] = 1;
  ans['Q'] = 1;
  ans['R'] = 1;
  long long total = 0;
  while (cin >> line) {
    for (auto &i: line) {
      total += ans[i];
    }
    cout << total << endl;
  }
  return 0;
}
