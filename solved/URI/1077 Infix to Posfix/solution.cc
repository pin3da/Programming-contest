#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string nonterm = "()+-*/^";

bool terminal(char c) {
  return nonterm.find(c) == string::npos;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    string line; cin >> line;
    deque<char> q;
    line = '(' + line + ')';
    for (int i = 0; i < line.size(); ++i) {
      char cur = line[i];
      if (cur == '(') {
        q.push_back(cur);
      }
      else if (cur == ')') {
        while (q.back() != '(') {
          cout << q.back();
          q.pop_back();
        }
        q.pop_back();
      }
      else if (cur == '+' || cur == '-') {
        while (q.back() != '(') {
          cout << q.back();
          q.pop_back();
        }
        q.push_back(cur);
      }

      else if (cur == '*' || cur == '/') {
        string t = "(+-";
        while (t.find(q.back()) == string::npos) {
          cout << q.back();
          q.pop_back();
        }
        q.push_back(cur);
      }

      else if (cur == '^') {
        string t = "(+-*/";
        while (t.find(q.back()) == string::npos) {
          cout << q.back();
          q.pop_back();
        }
        q.push_back(cur);
      }

      else {
        cout << cur;
      }
    }
    cout << endl;
  }
  return 0;
}
