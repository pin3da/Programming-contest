#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

string names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};


int frec(string s, string target) {
  int pos = 0;
  int ans = 0;
  while ((pos = s.find(target, pos )) != string::npos) {
    ans++;
    pos += target.length();
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;

  int seen = 0;
  for (string name : names) {
    int t = frec(line, name);
    seen += t;
  }
  puts(seen == 1 ? "YES" : "NO");

  return 0;
}
