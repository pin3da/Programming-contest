/**
* not solved yet
*/
using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

int contar(int a,int b){
    int ans = 0;
    for(;a%b==0;++ans,a/=b);
    return ans;
}

pair<int, string> dp[1001][1001];
int mat[1001][1001];

void fill_dp(int a,int n){
    For(i,n)
        For(j,n)
            dp[i][j].first=0,dp[i][j].second="";
    
   For(i,n){
        dp[0][i].first = contar(mat[0][i],a);
        dp[i][0].first = contar(mat[i][0],a);
        if(i!=0) {
            dp[0][i].second =  dp[0][i-1].second + "R";
            dp[i][0].second =  dp[i-1][0].second + "D";
            dp[0][i].first +=  dp[0][i-1].first + contar(mat[0][i],a);
            dp[i][0].first +=  dp[i-1][0].first + contar(mat[i][0],a);
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1; j<n;++j){
            if(dp[i][j-1].first < dp[i-1][j].first){
                dp[i][j].first = dp[i][j-1].first + contar(mat[i][j],a);
                dp[i][j].second = dp[i][j-1].second+"R";
            }else{
                dp[i][j].first = dp[i-1][j].first + contar(mat[i][j],a);
                dp[i][j].second = dp[i-1][j].second+"D";
            }
        }
    }

}


int main(){
    
    int n;cin>>n;

    int ceros = 0;
    For(i,n){
        For(j,n){
            cin>>mat[i][j];
        }
    }
     


    fill_dp(2,n);
    
    For(i,n){
        For(j,n){
            cout<<"\t"<<dp[i][j].second;
        }
        cout<<endl;
    }

    int dp1 = dp[n-1][n-1].first;
    string sdp1 = dp[n-1][n-1].second;
    fill_dp(5,n);
    int dp2 = dp[n-1][n-1].first;
    string sdp2 = dp[n-1][n-1].second;
    
    cout<<(min(dp1,dp2))<<endl;
    if(dp1 > dp2) cout<<sdp2<<endl;
    else cout<<sdp1<<endl;
    return 0;
}
