#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string line;
  getline(cin, line);
  for (auto &i : line) {
    if (i == '!') i = ' ';
    if (i == '.') i = ' ';
  }
  if (line.find("?") != string::npos) {
    cout << "7" << endl;
  } else if (line.find("Sussu") != string::npos) {
    stringstream ss(line);
    while (ss >> line) {
      if (line == "Sussu") {
        cout << "AI SUSSU!" << endl;
        return 0;
      }
    }
    cout << "O cara é bom!" << endl;
  } else {
    cout << "O cara é bom!" << endl;
  }
  return 0;
}
