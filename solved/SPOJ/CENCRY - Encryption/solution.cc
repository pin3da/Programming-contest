#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string vowel = "aeiou";
string non_v = "bcdfghjklmnpqrstvwxyz";


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--) {
    string line; cin >> line;
    vector<int> frec(30);
    for (auto &i : line) {
      frec[i - 'a']++;
      if (vowel.find(i) != string::npos) {
        int idx = vowel.find(i) + (frec[i - 'a'] - 1) * vowel.size();
        cout << non_v[(idx) % non_v.size()];
      } else {
        int idx = non_v.find(i) + (frec[i - 'a'] - 1) * non_v.size();
        cout << vowel[idx % vowel.size()];
      }
    }
    cout << endl;
  }

  return 0;
}
