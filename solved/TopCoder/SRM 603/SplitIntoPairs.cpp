using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(), (x).end()

class SplitIntoPairs {
  public:
    int makepairs(vector <int> A, int X) {
      long long pos = 1000000001, neg = -1000000001;
      int p = 0,n = 0;
      for(int i = 0;i < A.size(); ++i){
        if(A[i] >= 0) {
          p++;
          pos = min(pos,(long long) A[i]);
        }else{
          n++;
          neg = max(neg,(long long) A[i]);
        }
      }
      if((p%2) == 0) return A.size()/2;

      int tmp =  A.size()/2;
      if(neg*pos < X) tmp--;
      return tmp;
    }
};
