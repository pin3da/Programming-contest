#include<bits/stdc++.h>
using namespace std;

string toPrint(int x){
  string ret;
  while(x) {
    int m = x % 10;
    if( m == 2) {
      ret.push_back('5');
    }else if(m == 5) {
      ret.push_back('2');
    }else if(m == 6) {
      ret.push_back('9');
    }else if(m == 9) {
      ret.push_back('6');
    }else{
      ret.push_back('0' + m);
    }
    x /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  string s;
  while(cin >> s) {
    vector<int> num(255,0);
    int co = 1;
    for(int i = 0; i < s.size(); i++) {
      if(num[s[i]]) continue;
      num[s[i]] = co++;
    }
    for(int i = 0; i < s.size(); i++) {
      cout << toPrint(num[s[i]]);
    }
    cout << endl;
  }
}
