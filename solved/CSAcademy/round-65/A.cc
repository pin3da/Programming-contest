#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line, order;
  cin >> line >> order;
  for (auto &i : line) {
    cout << order[i - 'a'];
  }
  cout << endl;
  return 0;
}
