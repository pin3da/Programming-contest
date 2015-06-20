using namespace std;
#include <bits/stdc++.h>
map<int, string> co;

string f(int i) {
  if (co.count(i)) return co[i];
  string tmp = "[" + co[2] + "]" + "*+[" + f(i / 2)+"]";
  if (i & 1) {
    tmp += co[1];
  }
  return tmp;
}

int main() {

  co[0] = "+![]";
  co[1] = "+!![]";
  co[2] = "+!![]+!![]";
  for (int i = 0; i < 1001; ++i) {
    string t = f(i);
    if (t.size() > 200) break;
    cout << t << endl;
  }
  return 0;
}
