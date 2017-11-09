#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";


int find_any(string line, string s) {
  for (auto i : s) {
    if (line.find(i) != string::npos)
      return true;
  }
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  string line; cin >> line;

  int ans = 0;
  if (!find_any(line, numbers)) ans++;
  if (!find_any(line, lower_case))ans++;
  if (!find_any(line, upper_case)) ans++;
  if (!find_any(line, special_characters)) ans++;

  ans += max<int>(0, 6 - (line.size() + ans));
  cout << ans << endl;
  return 0;
}
