#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  string line;
  getline(cin, line);
  while (n--) {
    getline(cin, line);
    set<char> cur;
    for (auto &i : line)
      if (isalpha(i))
        cur.insert(i);
    if (cur.size() == 26)
      cout << "frase completa" << endl;
    else if (cur.size() >= 13)
      cout << "frase quase completa" << endl;
    else
      cout << "frase mal elaborada" << endl;
  }
  return 0;
}
