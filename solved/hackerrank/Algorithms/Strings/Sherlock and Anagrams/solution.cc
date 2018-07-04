#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int Anagrams(string &s) {
  int ans = 0;
  map<vector<int>, int> anagramFrec;
  for (int i = 0; i < int(s.size()); i++) {
    vector<int> frec(26);
    for (int j = i; j < int(s.size()); j++) {
      frec[s[j] - 'a']++;
      ans += anagramFrec[frec];
      anagramFrec[frec]++;
    }
  }
  return ans;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    cout << Anagrams(s) << endl;
  }
  return 0;
}
