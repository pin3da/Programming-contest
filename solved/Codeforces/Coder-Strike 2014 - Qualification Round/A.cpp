// http://codeforces.com/contest/411/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  string line;
  cin>>line;
  int ok = 1;
  if (line.size() < 5) ok = false;
  int lower = 0, upper = 0, digit = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (islower(line[i])) lower = 1;
    if (isupper(line[i])) upper = 1;
    if (isdigit(line[i])) digit = 1;
  }
  ok = ok and lower and upper and digit;

  if (ok)
    cout<<"Correct"<<endl;
  else
    cout<<"Too weak"<<endl;

  return 0;
}