#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int digit(string &a, long long &x) {
  x = 0;
  for (auto &i: a) {
    if (!isdigit(i))
      return 0;
    x *= 10;
    x += i - '0';
  }
  return true;
}

string ops = "+-*/";

int ok, id, div_zero;
deque<string> q;

long long parse() {
  if (id == q.size()) {
    ok = false;
    return 0;
  }
  if (ops.find(q[id]) != string::npos) {
    string op = q[id];
    id++;
    long long x = parse(), y = parse();
    if (op == "+")
      return x + y;
    if (op == "-")
      return y - x;
    if (op == "*")
      return y * x;
    if (op == "/") {
      if (x == 0) {
        div_zero = true;
        return 0;
      }
      return y / x;
    }
  } else {
    long long x;
    if (!digit(q[id], x)) {
      ok = false;
      return 0;
    }
    id++;
    return x;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    if (line.size() == 0) {
      cout << "Invalid expression." << endl;
      continue;
    }
    q.clear();
    stringstream ss(line);
    while (ss >> line)
      q.push_back(line);

    ok = true, id = 0, div_zero = 0;
    long long ans = parse();
    if (!ok || id < q.size()) {
      cout << "Invalid expression." << endl;
    } else {
      if (div_zero)
        cout << "Division by zero."  << endl;
      else
        cout << "The answer is " << ans << "." << endl;
    }

  }
  return 0;
}
