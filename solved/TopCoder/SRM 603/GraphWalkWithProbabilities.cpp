using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl


vector<long double> win, loose, st;
vector<string> g;
long double dp[55];
int s;

class GraphWalkWithProbabilities {
  public:
    double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) {
      g = graph;
      s = g.size();
      win.resize(s);
      loose.resize(s);
      st.resize(s);
      for(int i = 0; i < win.size(); ++i){
        st[i] = (100 - winprob[i] - looseprob[i])/100.0;
        win[i] = winprob[i] / 100.0;
        dp[i] = (winprob[i])/(double)(winprob[i] + looseprob[i]);
      }

      for(int k = 0; k < 2000; ++k){
        for(int i = 0; i < s; ++i ){
          for(int j = 0; j < s; ++j){
            if(g[i][j] == '1')
                dp[i] = max(dp[i] , win[j] + st[j]*dp[j]);
          }
        }
      }
      return dp[Start];

  }
};
