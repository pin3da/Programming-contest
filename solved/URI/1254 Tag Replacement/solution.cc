#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void tol(string &data) {
    transform(data.begin(), data.end(), data.begin(), ::tolower);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string tag, rep;
  while (getline(cin, tag)) {
    getline(cin, rep);
    string line; getline(cin, line);
    string cpline = line;
    string cprep = rep;
    tol(tag);
    tol(rep);
    tol(line);
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '<') {
        int ends = line.find(">", i);
        int idx;
        while ((idx = line.find(tag, i)) != string::npos && (idx < ends)) {
          line.replace(idx, tag.size(), rep);
          cpline.replace(idx, tag.size(), cprep);
          ends = line.find(">", i);
        }
      }
    }
    cout << cpline << endl;
  }
  return 0;
}
