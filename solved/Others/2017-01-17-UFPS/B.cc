#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool solve(map<string, double> &dic) {
  string line;
  getline(cin, line);
  vector<string> tokens;
  stringstream ss(line);
  while (ss >> line)
    tokens.push_back(line);
  double ans = stod(tokens.back()); tokens.pop_back();
  string op = tokens.back(); tokens.pop_back();
  double cur = 0;
  for (string &s : tokens)
    if (s != "+")
      cur += dic[s];

  if (op == "<")
    return cmp(cur, ans) == -1;
  if (op == ">")
    return cmp(cur, ans) == 1;
  if (op == "<=")
    return cmp(cur, ans) != 1;
  if (op == ">=")
    return cmp(cur, ans) != -1;
  if (op == "=")
    return cmp(cur, ans) == 0;

  assert(false);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int p, g;
  string buffer;
  getline(cin, buffer); stringstream ss(buffer);
  ss >> p >> g;
  map<string, double> data;
  while (p--) {
    string name;
    double val;
    getline(cin, buffer); stringstream ss(buffer);
    ss >> name >> val;
    data[name] = val;
  }

  for (int i = 0; i < g; ++i) {
    cout << "Guess #" << (i + 1) << " was ";
    cout << (solve(data) ? "correct" : "incorrect") << "."  << endl;
  }
  return 0;
}
