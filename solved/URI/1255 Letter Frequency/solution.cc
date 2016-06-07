#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  string line;
  getline(cin, line);
  while (tc--) {
    getline(cin, line);
    vector<int> frec(300);
    for (auto &i : line)
      if (isalpha(i))
        frec[tolower(i)]++;

    int best = *max_element(frec.begin(), frec.end());
    for (char i = 'a'; i <= 'z'; ++i)
      if (frec[i] == best)
        cout << i;
    cout << endl;
  }

  return 0;
}
