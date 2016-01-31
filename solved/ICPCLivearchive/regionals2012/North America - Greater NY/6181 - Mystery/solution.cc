#include <bits/stdc++.h>
using namespace std;

void get_int(int &x) {
  string s;
  getline(cin, s);
  stringstream ss(s);
  ss >> x;
}

vector<int> get_array() {
  vector<int> ans;
  string s;
  getline(cin, s);
  stringstream ss(s);
  int x;
  while (ss >> x)
    ans.push_back(x);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int p; get_int(p);

  for (int k = 0; k < p; k++) {
    int id; get_int(id);
    string s; getline(cin, s);
    // cout << s << endl;
    int n; get_int(n);
    vector<int> x = get_array();

    int ptr = 0;
    cout << id << " ";
    for (int i = 0; i < n; i++) {
      ptr = (ptr + x[i] + s.size()) % s.size();
      cout << s[ptr];
    }
    cout << endl;
  }

  return 0;
}
