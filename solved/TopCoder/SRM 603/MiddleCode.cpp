using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

class MiddleCode {
  public:
    string encode(string s) {
      string t;
      while(s.size()){

        if(s.size()%2){
          t.push_back(s[s.size()/2]);
          s.erase(s.size()/2,1);
        }else{
          int pos = s.size()/2;
          if(s[pos] <= s[pos-1]){
            t.push_back(s[pos]);
            s.erase(pos,1);
          }else{
            t.push_back(s[pos-1]);
            s.erase(pos-1,1);
          }
        }
      }
      return t;
   }
};
