#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<char, char> k;
  k['1'] = '`';
  k['2'] = '1';
  k['3'] = '2';
  k['4'] = '3';
  k['5'] = '4';
  k['6'] = '5';
  k['7'] = '6';
  k['8'] = '7';
  k['9'] = '8';
  k['0'] = '9';
  k['-'] = '0';
  k['='] = '-';

  k['W'] = 'Q';
  k['E'] = 'W';
  k['R'] = 'E';
  k['T'] = 'R';
  k['Y'] = 'T';
  k['U'] = 'Y';
  k['I'] = 'U';
  k['O'] = 'I';
  k['P'] = 'O';
  k['['] = 'P';
  k[']'] = '[';
  k['\\'] = ']';

  k['S'] = 'A';
  k['D'] = 'S';
  k['F'] = 'D';
  k['G'] = 'F';
  k['H'] = 'G';
  k['J'] = 'H';
  k['K'] = 'J';
  k['L'] = 'K';
  k[';'] = 'L';
  k['\''] = ';';

  k['X'] = 'Z';
  k['C'] = 'X';
  k['V'] = 'C';
  k['B'] = 'V';
  k['N'] = 'B';
  k['M'] = 'N';
  k[','] = 'M';
  k['.'] = ',';
  k['/'] = '.';
  k[' '] = ' ';

  string line;
  while (getline(cin, line)) {
    for (auto &i : line) {
      if (k.count(i))
        cout << k[i];
      else
        cout << i;
    }
    cout << endl;
  }

  return 0;
}

