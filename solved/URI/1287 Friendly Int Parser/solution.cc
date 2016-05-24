#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string trim(string a) {
  deque<char> q;
  for (auto &i : a) q.push_back(i);
  while (q.size() > 1 && q.front() == '0') q.pop_front();
  string ans(q.begin(), q.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  unordered_map<char, int> t;
  for (char i = '0'; i <= '9'; ++i) t[i] = i;
  t['o'] = '0';
  t['O'] = '0';
  t['l'] = '1';
  string line;
  while (getline(cin, line)) {
    string tmp;
    int err = 0;
    for (auto &i : line) {
      if (i == ',' || i == ' ') continue;
      if (!t.count(i)) {
        err = 1;
        break;
      }
      tmp.push_back(t[i]);
    }
    tmp = trim(tmp);
    if (!err && tmp.size() && tmp.size() < 11) {
      long long a = stoll(tmp);
      if (a > 2147483647LL)
        cout << "error" << endl;
      else
        cout << a << endl;
    } else
      cout << "error" << endl;
  }

  return 0;
}
