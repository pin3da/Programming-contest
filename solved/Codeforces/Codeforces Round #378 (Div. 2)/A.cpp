// http://codeforces.com/contest/733/problem/A

#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

string voc = "AEIOUY";

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int ant = -1;
  string line; cin >> line;
  int best = 0;
  for (int i = 0; i < (int)line.size(); ++i) {
    if (voc.find(line[i]) != string::npos) {
      best = max(best, i - ant);
      ant = i;
    }
  }
  best = max(best, (int)line.size() - ant);
  cout << best << endl;
  return 0;
}
