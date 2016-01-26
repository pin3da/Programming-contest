#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    if (line.size() > 1 && line[0] == '0' && line[1] == 'x') {
      stringstream ss;
      ss << hex << line;
      long long ans;
      ss >> ans;
      cout << dec << ans << endl;
    } else {
      stringstream ss;
      ss << line;
      long long ans;
      ss >> ans;
      if (ans < 0) return 0;
      stringstream s2;
      s2 << hex << ans;
      string t;
      s2 >> t;
      for (int i = 0; i < t.size(); ++i)
        t[i] = toupper(t[i]);
      cout << "0x" << t << endl;
    }
  }
  return 0;
}
