#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);
  while (fib.back() <= 1000) {
    int n = fib.size();
    int cur = fib[n - 2] + fib[n - 1];
    fib.push_back(cur);
  }

  string ans(1001, 'o');
  for (auto i : fib)
    ans[i - 1] = 'O';


  int len;
  cin >> len;
  cout << ans.substr(0, len) << endl;

  return 0;
}
