#include <bits/stdc++.h>

using namespace std;

int nextint() {
  string buff;
  getline(cin, buff);
  return atoi(buff.c_str());
}
int main() {
  int tc = nextint();
  while (tc--) {
    string line;
    getline(cin, line);
    int ant = 1, t;
    long long ans = 0;
    stringstream ss(line);
    while (ss >> t) {
      if (ant * 2 < t) {
        ans += t - ant * 2;
      }
      ant = t;
    }
    cout << ans << endl;
  }
  return 0;
}
