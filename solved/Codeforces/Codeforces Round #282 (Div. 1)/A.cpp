// http://codeforces.com/contest/494/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  string line;
  cin >> line;
  int last = -1, b = 0, e = 0;
  int e1, b1;
  for (int i = 0; i < line.size(); ++i) {
    b1 += (line[i] == '(');
    e1 += (line[i] == ')');

    if (line[i] == '#') {
      last = i;
      b1 = e1 = 0;
    }
  }


  vector<int> ans;
  for (int i = 0; i < line.size(); ++i) {
    b += (line[i] == '(');
    e += (line[i] == ')');
    if (e > b) {
      cout << -1 << endl;
      return 0;
    }

    if (line[i] == '#') {
      if (i == last) {
        int missing = b  + b1 - e - e1;
        // D(missing);
        if (missing <= 0 or e + missing > b) {
          cout << -1 << endl;
          return 0;
        }
        ans.push_back(missing);
        e += missing;
      } else {
        if (e + 1 > b) {
          cout << -1 << endl;
          return 0;
        }
        ans.push_back(1);
        e += 1;
      }
    }
  }

  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;

  return 0;
}