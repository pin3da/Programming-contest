#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  string line;
  getline(cin, line);
  while (n--) {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    int cheater = 0;
    set<char> eaten;
    vector<bool> seen(a.size());
    for (int i = 0; i < b.size(); ++i) {
      if (a.find(b[i]) == -1 || eaten.count(b[i])) {
        cheater = true;
      } else {
        seen[a.find(b[i])] = true;
      }
      eaten.insert(b[i]);
    }
    for (int i = 0; i < c.size(); ++i) {
      if (a.find(c[i]) == -1 || eaten.count(c[i])) {
        cheater = true;
      } else {
        seen[a.find(c[i])] = true;
      }
      eaten.insert(c[i]);
    }

    if (cheater) {
      cout << "CHEATER" << endl;
    } else {
      vector<char> ans;
      for (int i = 0; i < a.size(); ++i)
        if (!seen[i]) ans.push_back(a[i]);
      sort(ans.begin(), ans.end());
      for (auto &i : ans)
        cout << i;
      cout << endl;
    }
  }

  return 0;
}
