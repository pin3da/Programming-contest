#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;

  deque<char> ans;
  while (n > 0) {
    if (n & 1) {
      ans.push_front('A');
      n = (n - 1) >> 1;
    } else {
      ans.push_front('B');
      n = (n - 2) >> 1;
    }
  }

  for (auto i : ans)
    cout << i;
  cout << endl;
  return 0;
}
