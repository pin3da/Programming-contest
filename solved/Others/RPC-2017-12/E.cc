#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl


bool isnumber(string &x) {
  for (int i = 0; i < x.size() - 1 ; i++) {
    if (!isdigit(x[i]) && x[i] != '-') return false;
  }
  return true;
}


long long ton(string x) {
  stringstream ss;
  ss << (x.substr(0, x.size() - 1));
  long long ret; ss >> ret;
  return ret;
}

bool cmp(string a, string b) {
  for (int i = 0; i < a.size(); i++) {
    if (isupper(a[i])) a[i] = 'a' + (a[i] - 'A');
  }
  for (int i = 0; i < b.size(); i++) {
    if (isupper(b[i])) b[i] = 'a' + (b[i] - 'A');
  }
  return a < b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  while (getline(cin, line) && line != ".") {
    stringstream ss; ss << line;
    string x;
    vector<int> numbers;
    vector<string> strings;
    vector<bool> kind;
    int hw = 0;
    while (ss >> x) {
      if (isnumber(x)) {
        kind.push_back(1);
        numbers.push_back(ton(x));
      } else {
        kind.push_back(0);
        strings.push_back(x.substr(0, x.size() - 1));
      }
    }

    sort(numbers.begin(), numbers.end());
    sort(strings.begin(), strings.end(), cmp);

    int nu = 0, st = 0;
    for (int i = 0; i < kind.size(); i++) {
      if (i && i < kind.size()) cout << ", ";
      if (kind[i]) {
        cout << numbers[nu++];
      } else {
        cout << strings[st++];
      }
    }
    cout << '.' << endl;
  }

  return 0;
}
