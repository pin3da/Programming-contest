using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

class TypoCoderDiv2 {
  public:
    int count(vector <int> rating) {
      int act = 1;
      int ans = 0;
      for(int i = 0; i < rating.size(); ++i){
        if((act == 1)  and (rating[i] >= 1200)){
          ans++;
          act = 2;
          continue;
        }
        if((act == 2) and rating[i] < 1200){
          ans++;
          act = 1;
        }
      }
      return ans;
    }
};
