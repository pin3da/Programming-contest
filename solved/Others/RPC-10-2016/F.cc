#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 100 - 8;
long long fib[MN];
vector<int> match[11];

string conv(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fib[0] = fib[1] = 1;
  vector<string> fs(MN);
  fs[0] = fs[1] = "1";
  for (int i = 2; i < MN; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fs[i] = conv(fib[i]);
  }

  vector<string> concat;
  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j < MN; ++j) {
      if (i != j)
        concat.push_back(fs[i] + fs[j]);
    }
  }

  sort(concat.begin(), concat.end());
  concat.resize(unique(concat.begin(), concat.end()) - concat.begin());

  string line;
  while (cin >> line) {

    for (int i = 0; i < 10; i++) match[i].clear();
    for (int i = 0; i < line.size(); ++i) {
      if (isdigit(line[i])) match[line[i] - '0'].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < concat.size(); ++i) {
      int last = -1, j;
      for(j = 0; j < concat[i].size(); j++) {
        int x = concat[i][j] - '0';

        vector<int>::iterator newlast = upper_bound(match[x].begin(), match[x].end(), last);
        if (newlast == match[x].end()) break;
        last = *newlast;
      }
      if ((j == concat[i].size())) {
        ans ++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
