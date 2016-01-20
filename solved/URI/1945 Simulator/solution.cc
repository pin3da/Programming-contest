#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

vector<string> parse(string s) {
  stringstream ss(s);
  vector<string> ans;
  string t;
  while (ss >> t)
    ans.push_back(t);
  return ans;
}

int parse_t(unordered_map<string, int> &v, string &t) {
  if (isdigit(t[0])) {
    int val = 0;
    for (int i = 0; i < t.size(); ++i)
      val = (val * 10) + (t[i] - '0');
    return val;
  }
  return v[t];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  unordered_map<string, int> v;
  int last = -1;
  while (getline(cin, line)) {
    vector<string> tokens = parse(line);
    if (tokens.size() == 3) {
      last = parse_t(v, tokens[2]);
      v[tokens[0]] = last;
    } else {
      last = parse_t(v, tokens[2]) + parse_t(v, tokens[4]);
      v[tokens[0]] = last;
    }
  }

  // for (auto &i : v)
  //  cout << i.first << " := " << i.second << endl;
  assert(last >= 0);
  cout << last << endl;

  return 0;
}
