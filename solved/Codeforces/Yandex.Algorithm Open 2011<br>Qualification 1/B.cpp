// http://codeforces.com/contest/81/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100001

string line;
string ans;

void parse(int i) {

  if (i == line.size()) return;

  if (line[i] == '.') {

    int esp = 0;
    int j = i - 1;
    while (j >= 0) {
      if(line[j] == ' ') j--;
      else if (line[j] != ',') {
        esp = 1;
        break;
      } else {
        esp = 0;
        break;
      }
    }

    if (esp)  ans += " ";

    int c = 0;
    while (c < 3) {
      if (line[i] == '.') c++;
      i++;
    }
    ans += "...";
    parse (i);
    return;
  } else if (isdigit(line[i])){

    int esp = 0;
    int j = i - 1;
    while (j >= 0) {
      if(line[j] == ' ') j--;
      else if (isdigit(line[j])) {
        esp = 1;
        break;
      } else {
        esp = 0;
        break;
      }
    }

    if (esp)  ans += " ";

    while (isdigit(line[i])) {
      ans += line[i];
      i++;
    }
    parse(i);
    return;

  } else if (line[i] == ',') {
    ans += ", ";
    parse(i+1);
    return;
  }
  parse(i+1);


}

int main() { ___

  getline(cin, line);
  parse(0);
  if (ans[0] == ' ') ans = ans.substr(1, ans.size() - 1);
  if (ans[ans.size() - 1] == ' ') ans = ans.substr(0, ans.size() - 1);

  cout<<ans<<endl;
  return 0;
}