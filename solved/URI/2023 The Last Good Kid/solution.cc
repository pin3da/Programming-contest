#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string convert(string a) {
  for (auto &i : a) i = tolower(i);
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  string ans = "";
  while (getline(cin, line))
    if (convert(line) > convert(ans))
      ans = line;
  cout << ans << endl;
  return 0;
}
