#include <bits/stdc++.h>

using namespace std;

string random_word(int len, int alpha) {
  int s = (random() % len) + 1;
  string ans;
  while (ans.size() < s) {
    ans.push_back('a' + (random() % alpha));
  }
  return ans;
}

int main() {
  srand(time(0));
  int alpha = 10;
  int d = (random() % 100) + 1;
  int maxsize = 100000 / d;
  cout << d << " " << alpha << endl;
  for (int i = 0; i < d; ++i) {
    cout << random_word(maxsize, alpha) << endl;
  }
  int s = (random() % 300) + 1;
  cout << s << endl;
  int ms = 3000 / s;
  for (int i = 0; i < s; ++i) {
    cout << random_word(ms, alpha) << " " << 1 + (random() % 50) << endl;
  }
  return 0;
}
