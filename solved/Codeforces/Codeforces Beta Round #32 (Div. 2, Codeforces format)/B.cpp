// http://codeforces.com/contest/32/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '.') cout << 0;
      else if (line[i] == '-' && line[i + 1] == '.') { cout << 1; ++i;}
      else if (line[i] == '-' && line[i + 1] == '-') { cout << 2; ++i;}
      else assert(false);
    }
    cout << endl;
  }
  return 0;
}
