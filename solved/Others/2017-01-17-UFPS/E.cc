#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 34567;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  deque<int> cur;
  for (int i = 2; i < MN; ++i)
    cur.push_back(i);

  deque<int> lucky;
  while (cur.size()) {
    int mod = cur.front();
    deque<int> ne;
    for (int i = 0; i < (int)cur.size(); ++i)
      if (i % mod)
        ne.push_back(cur[i]);
    lucky.push_back(mod);
    cur = ne;
  }
  int n;
  while (cin >> n && n) {
    cout << lucky[n - 1] << endl;
  }
  return 0;
}
