// http://codeforces.com/contest/526/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() { ___
  int n;
  cin >> n;
  string line;
  cin >> line;
  for (int j = 0; j < line.size(); ++j) {
    if (line[j] == '*') {
      for (int i = 1; i < line.size(); ++i) {
        int count = 0;
        int cur = j;
        while (true) {
          cur += i;
          if (cur < line.size() && line[cur] == '*')
            count++;
          else
            break;
        }
        if (count >= 4) {
          cout << "yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "no" << endl;

  return 0;
}
