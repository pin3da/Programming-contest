#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int val[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void backtrack(int len, int k, vector<deque<int>> &all, deque<int> cur) {
  if (k < 0) return;
  if (len == (int)cur.size() && (k == 0)) {
    all.push_back(cur);
    return;
  }

  cur.push_back(0);
  int n = cur.size() - 1;
  for (int i = 0; i < 10; i++) {
    cur[n] = i;
    backtrack(len, k - val[i], all, cur);
  }
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int k; cin >> k;
  vector<deque<int>> ans;
  int missing = 0;
  while (k > 21) k -= 7, missing++;

  int len = (k + 6) / 7;
  deque<int> tmp;
  backtrack(len, k, ans, tmp);
  sort(ans.begin(), ans.end());
  for (auto i: ans) {
    if (i[0] == 0 && (i.size() != 1)) continue;
    for (auto j : i) {
      cout << j;
    }
    cout << string(missing, '8');
    cout << endl;
    break;
  }
  if (ans.size() == 0) {
    cout << -1 << endl;
  }

  return 0;
}
