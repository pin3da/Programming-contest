#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    puts(line.find("i") == string::npos ? "S" : "N");
  }
  return 0;
}
