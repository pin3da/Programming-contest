#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  cin >> line;
  int n; cin >> n;
  vector<int> p(line.size() + 1);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    t--;
    p[t]++;
    p[line.size() - t]--;
  }

  for (int i = 1 ; i < line.size(); ++i) {
    p[i] += p[i - 1];
    // cout << p[i] << " ";
  }

  for (int i = 0 ; i < line.size(); ++i) {
    if (p[i] & 1) {
      cout << line[line.size() - i - 1];
    }  else {
      cout << line[i];
    }
  }
  cout << endl;
  return 0;
}
