#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int charToInt(char c) { return c == ' ' ? 0 : c - 'a' + 1; }
char intToChar(int x) { return x == 0 ? ' ' : x + 'a' - 1; }

int nextInt() {
  string num; getline(cin, num);
  return atoi(num.c_str());
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int t = nextInt();
  while (t--) {
    string input; getline(cin, input);
    string line = input.substr(2, input.size() - 2);
    int n = line.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = charToInt(line[i]);
    if (input[0] == 'e') {
      for (int i = 1; i < n; i++)
        v[i] = (v[i] + v[i - 1]) % 27;
    } else {
      for (int i = n - 1; i > 0; i--)
        v[i] = (((v[i] - v[i - 1]) % 27) + 27) % 27;
    }
    string ans;
    for (int i = 0; i < n; i++)
      ans.push_back(intToChar(v[i]));
    cout << ans << endl;
  }
  return 0;
}
