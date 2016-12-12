#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string name;
  vector<string> p, q;
  size_t best = 0;
  string ans;
  while (cin >> name && name != "FIM") {
    string reg; cin >> reg;
    if (reg == "YES") {
      p.push_back(name);
      if (name.size() > best) {
        best = name.size();
        ans = name;
      }
    } else
      q.push_back(name);
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  q.resize(unique(q.begin(), q.end()) - q.begin());
  for (int i = 0; i < (int)p.size(); ++i)
    cout << p[i] << endl;
  for (int i = 0; i < (int)q.size(); ++i)
    cout << q[i] << endl;

  cout << endl;
  cout << "Amigo do Habay:" << endl << ans << endl;
  return 0;
}
