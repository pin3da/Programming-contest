using namespace std;
#include <bits/stdc++.h>

int main() {
  string line;
  cin  >> line;

  int ans = 0;
  while (line != "0") {
    string t = line;
    sort(t.begin(), t.end());
    int a = atoi(line.c_str());
    int b = atoi(t.c_str());
    line = to_string(a - b);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
