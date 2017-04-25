// http://codeforces.com/contest/659/problem/C

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

const int MN = 200002;
typedef bitset<200002> mask;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;
  while (cin >> n >> m) {
    mask cur;
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (t < MN)
        cur.set(t);
    }
    vector<int> ans;
    ans.reserve(MN);
    long long acc = 0;
    for (int i = 1; i < MN; ++i) {
      if (!cur.test(i)) {
        if (acc + i > m) break;
        ans.push_back(i);
        acc += i;
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
