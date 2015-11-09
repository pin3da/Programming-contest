using namespace std;
#include <bits/stdc++.h>

char base[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

int main() {
  int a; cin >> a;
  multiset<string> f;
  string line;
  for (int i = 0; i < a; ++i) {
    cin >> line;
    for (int j = 0; j < line.size(); ++j) {
      line[j] = base[line[j] - 'a'];
    }
    f.insert(line);
  }
  cin >> line;
  cout << f.count(line) << endl;
  return 0;
}
