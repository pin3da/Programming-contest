// http://codeforces.com/contest/629/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> man(400), woman(400);
    for (int i = 0; i < n; ++i) {
      char g;
      int from , to;
      cin >> g >> from >> to;
      for (int j = from; j <= to; ++j)
        if (g == 'F')
          woman[j]++;
        else
          man[j]++;
    }

    int best = 0;
    for (int i = 0; i < 400; ++i) {
      best = max(best, min(woman[i], man[i]));
    }

    cout << (best << 1) << endl;
  }

  return 0;
}