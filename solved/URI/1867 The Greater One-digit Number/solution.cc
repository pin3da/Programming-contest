#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int one(string &a) {
  while (a.size() > 1) {
    long long sum = 0;
    for (auto &i : a)
      sum += i - '0';

    a = to_string(sum);
  }
  return atoi(a.c_str());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  while (cin >> a >> b && (a != "0" || b != "0")) {
    int aa = one(a),
        bb = one(b);

    if (aa == bb)
      cout << 0 << endl;
    else if (aa < bb)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
