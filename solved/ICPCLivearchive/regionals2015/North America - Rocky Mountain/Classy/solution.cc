#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct person {
  string name;
  deque<int> cl;
  bool operator < (const person &o) const {
    if (cl == o.cl)
      return name < o.name;
    return cl < o.cl;
  }
};

map<string, int> val;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  val["upper"] = 0;
  val["middle"] = 1;
  val["lower"] = 2;
  string line;
  while (getline(cin, line)) {
    int n = stoi(line);
    vector<person> p(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, line);
      stringstream ss(line);
      ss >> p[i].name;
      p[i].name = p[i].name.substr(0, p[i].name.size() - 1);
      while (ss >> line) {
        p[i].cl.push_front(val[line]);
      }
    }
    int mm = 0;
    for (int i = 0; i < n; ++i)
      mm = max<int>(mm, p[i].cl.size());

    for (int i = 0; i < n; ++i)
      while (p[i].cl.size() < mm)
        p[i].cl.push_back(1);

    sort(p.begin(), p.end());
    for (auto &i : p) {
      cout << i.name << endl;
    }
  }
  return 0;
}
