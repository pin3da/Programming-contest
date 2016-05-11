#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    string line;
    int a;
    cin >> line >> a;
    if (line == "Thor")
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
