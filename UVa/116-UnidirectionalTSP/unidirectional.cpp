using namespace std;
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <map>

#define D(x) cout<< #x " = "<<(x)<<endl
#define all(x) x.begin(),x.end()

template<class T>
string to_str(T x){ stringstream ss; ss<<x; return ss.str();}
template<class T>
int to_int(T x){ stringstream ss; ss<<x;int r;ss>>r; return r;}

int M[20][101];
int dp[20][101];
int p[20][101];
int n,m;

int ne(int k){
    int t = (k + n)%n;
    assert(t >= 0 and t < n);
    return t;
}

int solve(int i, int j){
    if(j == m-1) return M[i][j];
    int &ans = dp[i][j];
    
    if(ans != -1) return ans;
    
    vector <pair<int,int> > tmp;
    for(int k = -1; k< 2; ++k) tmp.push_back(make_pair(solve(ne(i+k),j+1) , ne(i+k)));
    sort(all(tmp));
    ans = tmp[0].first + M[i][j];
    p[i][j] = tmp[0].second;

    return ans;
}

string gen_path(int i, int j = 0){
    if(j==m-1) return to_str(i+1);
    else return to_str(i+1) + " " + gen_path(p[i][j],j+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
        for(int i = 0; i< n; ++i)
            for(int j = 0; j < m; ++j)
                cin>>M[i][j];
        
        int ans = (1<<30);
        int index;
        memset(dp,-1, sizeof(dp));
        for(int i = 0; i< n; ++i){
            if(solve(i,0) < ans){
                index = i;
                ans = solve(i,0);
            }
        }
        
        cout<<gen_path(index)<<endl<<ans<<endl;
    }
    
    return 0;
}
