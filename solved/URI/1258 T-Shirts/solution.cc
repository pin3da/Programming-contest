#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct entry {
  string name, color, size;
  entry() {}
  entry(string a, string b, string c) :
    name(a),
    color(b),
    size(c) {}

  bool operator < (const entry &o) const {
    if (color == o.color) {
      if (size ==  o.size) {
        return name < o.name;
      }
      return size > o.size;
    }
    return color < o.color;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  string buff;
  int first = true;
  while (getline(cin, buff) && buff != "0") {
    n = atoi(buff.c_str());
    vector<entry> a(n);
    string name;
    string line;
    for (int i = 0; i < n; ++i) {
      getline(cin, name);
      getline(cin, line);
      stringstream ss(line);
      string col, size;
      ss >> col >> size;
      a[i] = entry(name, col, size);
    }

    sort(a.begin(), a.end());
    if (!first)
      cout << endl;
    first = false;
    for (auto &i : a)
      cout << i.color << ' ' << i.size << ' ' << i.name << endl;
  }
  return 0;
}
