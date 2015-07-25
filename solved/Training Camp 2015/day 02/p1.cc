using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line && line != "#") {
    int ones = 0;
    for (int i = 0; i < line.size(); ++i) {
      ones += line[i] == '1';
    }

    if (line[line.size() - 1] == 'e') {
      if (ones & 1)
        line[line.size() - 1] = '1';
      else
        line[line.size() - 1] = '0';
    } else {
      if (ones & 1)
        line[line.size() - 1] = '0';
      else
        line[line.size() - 1] = '1';
    }
    cout << line << endl;
  }

  return 0;
}
