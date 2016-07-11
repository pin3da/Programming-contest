#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool neg(string s, string &ans) {
  bool can = false;
  ans = s;
  for (int i = s.size() - 1; i >= 1; --i) {
    if (s[i] != '9') {
      ans[i]++;
      can = true;
      break;
    }
  }
  return can;
}

bool pos(string &s, string &ans) {
  bool can = false;
  ans = s;
  for (int i = s.size() - 2; i >= 0; --i) {
    if (s[i] != '0' && s[i + 1] < '8') {
      ans[i]--;
      ans[i + 1] += 2;
      can = true;
      break;
    }
  }
  return can;
}

void print(string a) {
  int start = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != '0') {
      start = i;
      break;
    }
  }
  if (start > -1)
    cout << a.substr(start) << endl;
  else
    cout << "0" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string s;
  while (cin >> s && s != "END") {
    if (s[0] == '-') {
      string ans;
      if (neg(s, ans))
        print(ans);
      else
        print("-1" + ans.substr(1));
    } else {
      string tmp;
      bool ans = pos(s, tmp);
      if (!ans) {
        if (neg('-' + s, tmp)) {
          print(tmp);
        } else {
          print("-1" + tmp.substr(1));
        }
      } else {
        print(tmp);
      }
    }
  }

  return 0;
}
