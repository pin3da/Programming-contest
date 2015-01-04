using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

int next() {
  string buff;
  getline(cin, buff);
  return atoi(buff.c_str());
}

int is_vowel(char c) {
  c = tolower(c);
  string vv = "aeiou";
  for (int i = 0; i < vv.size(); ++i) {
    if (c == vv[i])
      return true;
  }
  return false;
}


int get_syll(string &s) {
  if (s.size() == 6) {
    if (s.find("ng") != string::npos)
      return 2;
    if (s.find("ny") != string::npos)
      return 2;
  }

  if (s.size() == 3) {
    if (is_vowel(s[0]))
      return 2;
  }

  if (s.size() >= 6)
    return 3;
  if (s.size() >= 4)
    return 2;
  return 1;
/*
 *  if (s.size() >= 6) {
 *    if (s.size() == 6 && (s.find("ng") != string::npos) || (s.find("ny") != string::npos))
 *      return 2;
 *    return 3;
 *  }
 *
 *  if (s.size() >= 4) {
 *    return 2;
 *  }
 *
 *  if (s.size() == 3 and is_vowel(s[0])) {
 *    return 2;
 *  }
 *  return 1;
 */
}

int parse(string &s) {
  stringstream ss(s);
  string w;
  int ans = 0;
  while (ss >> w) {
    // cout << w << " has " << get_syll(w) << endl;
    ans += get_syll(w);
  }
  return ans;
}

string last_two(string &s) {
  stringstream ss(s);
  string w;
  while (ss >> w);

  string tmp;
  tmp.push_back(w[w.size() - 2]);
  tmp.push_back(w[w.size() - 1]);

  return tmp;
}

void solve() {
  string line;
  getline(cin, line);
  vector<int> pantum;
  vector<string> ending;
  string verse;
  for (int i = 0; line[i] != '.'; ++i) {
    if (line[i] == ',') {
      pantum.push_back(parse(verse));
      ending.push_back(last_two(verse));
      verse = "";
    } else {
      verse.push_back(line[i]);
    }
  }
  pantum.push_back(parse(verse));
  ending.push_back(last_two(verse));

  int d = (pantum.size() > 4) ? (pantum.size() - 4) : 0;
  pantum.resize(min(pantum.size(), (size_t) 4));
  ending.resize(min(pantum.size(), (size_t) 4));
  int a = 0;
  for (int i = 0; i < pantum.size(); ++i) {
    // D(ending[i]);
    if (pantum[i] >= 8 and pantum[i] <= 12)
      a++;
  }

  int b = 0, c = 0;
  if (ending.size() > 2) {
    if (ending[0] == ending[2]) b++;
    if (pantum[0] == pantum[2]) c++;
  } if (ending.size() > 3) {
    if (ending[1] == ending[3]) b++;
    if (pantum[1] == pantum[3]) c++;
  }

  a = a * 10;
  b = b * 20;
  c = c * 10;
  d = d * 10;
  cout << a << ' ' << b << ' ' << c << ' '  << d << ' ' << (a + b + c - d) << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t = next();
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
