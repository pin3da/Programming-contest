#include<bits/stdc++.h>
using namespace std;

bool vowel(char c) {
  return (c == 'a') ||(c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}


int main() {
 int tc;
 cin >> tc;
 for (int i = 0; i < tc; ++i) {
  string line;
  cin >> line;
  int v = 0, c = 0;
  for (int j = 0; j < line.size(); ++j) {
    if (vowel(line[j]))  
      v++;
    else
      c++;
  }
  cout << line << endl;
  if (v > c)
    cout << 1 << endl;
  else
    cout << 0 << endl;
 }
}
