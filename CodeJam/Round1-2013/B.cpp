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
#include<cassert>
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int , int> pii;

vector<int> data;

int dp[20][20];
int ini,r,n;

int solve(int turno,int queda){
    if(dp[turno][queda]!=-1) return dp[turno][queda];
    if(turno==data.size()-1) return queda*data[data.size()-1];
    int mmax = -1;
    for(int i=queda;i>=0;--i){
        mmax = max(mmax,solve(turno+1,((queda-i+r <= ini)? queda-i+r : ini)) + i*data[turno]);
    }
    return dp[turno][queda] = mmax;
}

int main(){
    int nc;cin>>nc;
    for(int tid = 1; tid <= nc; ++tid){
        cin>>ini>>r>>n;
        data = vector<int>(n);
        for(int i=0;i<n;++i)
            cin>>data[i];
        memset(dp,-1,sizeof(dp));
        cout<<"Case #"<<tid<<": "<<(solve(0,ini))<<endl;
    }
    
    return 0;
}
