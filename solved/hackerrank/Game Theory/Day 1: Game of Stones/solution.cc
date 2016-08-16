#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 111;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> gn(MN);
  for (int i = 1; i < MN; ++i) {
    vector<int> mex(5);
    if (i >= 2) mex[gn[i - 2]] = true;
    if (i >= 3) mex[gn[i - 3]] = true;
    if (i >= 5) mex[gn[i - 5]] = true;
    for (int j = 0; j < 5; ++j)
      if (!mex[j]) {
        gn[i] = j;
        break;
      }
  }
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int n; cin >> n;
    puts(gn[n] ? "First" : "Second");
  }
  return 0;
}
