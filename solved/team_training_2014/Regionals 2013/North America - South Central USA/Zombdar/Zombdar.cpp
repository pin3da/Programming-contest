using namespace std;
#include<bits/stdc++.h>


void solve() {
  string line;
  int ts = 0;
  string cur = "";
  while (getline(cin, line)) {
    if (line == "END OF CASE")
      break;
    ts++;
    for (int i = 0; i < line.size(); ++i) {
      cur.push_back(line[i]);
      if (line[i] == ';') {
        cout<<ts<<": "<<cur<<endl;
        cur = "";
      }
    }

  }
}

int main() {

  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  string line;getline(cin, line);
  stringstream ss(line);
  ss>>tc;
  for (int i = 0; i < tc; ++i)
    solve();

  return 0;
}
