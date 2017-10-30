#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  if (line.find("b") == string::npos) {
    cout << line.size() << endl;
    return 0;
  }
  int i = 0; while (i < (int)line.size() && line[i] != 'b') i++;
  int j = line.size() - 1; while (j >= 0 && line[j] != 'b') j--;
  int ans = i + (line.size() - 1 - j);
  char last = 'c';
  int acc = 0;
  vector<int> frec;
  for (int k = i; k <= j; k++) {
    if (line[k] != last) {
      frec.push_back(acc);
      last = line[k];
      acc = 1;
    } else {
      acc++;
    }
  }
  frec.push_back(acc);
  vector<int> best(2);
  for (int i = 0; i < (int)frec.size(); i++) {
    best[i & 1] += frec[i];
  }
  cout << ans + max(best[0], best[1]) << endl;
  return 0;
}
