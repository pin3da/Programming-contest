#include <bits/stdc++.h>

using namespace std;

int step[] = {0, 2, 4, 5, 7, 9, 11, 12};

string ans[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<int> notes(n);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    notes[i] = (t - 1) % 12;
  }
  int seen = false;
  for (int i = 0; i < 12; i++) {
    vector<int> valid(12, 0);
    for (int j = 0; j < 7; j++) {
      valid[(i + step[j]) % 12] = true;
    }
    int ok = true;
    for (int j = 0; j < notes.size(); j++) {
      ok &= valid[notes[j]];
    }
    if (ok) {
      cout << ans[i]<< endl;
      seen = true;
      break;
    }
  }
  if (!seen) {
    cout << "desafinado" << endl;
  }
  return 0;
}
