#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string line;
  while (getline(cin, line) && line != "*") {
    stringstream ss(line);
    set<char> seen;
    while (ss >> line) {
      seen.insert(tolower(line[0]));
    }
    if (seen.size() == 1)
      cout << 'Y' << endl;
    else
      cout << 'N' << endl;
  }
  return 0;
}
