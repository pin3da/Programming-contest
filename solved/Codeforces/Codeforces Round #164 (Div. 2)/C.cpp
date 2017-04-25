// http://codeforces.com/contest/268/problem/C

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

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
typedef long long int lli;
typedef pair<int , int> pii;


int main(){
    int n,m;cin>>n>>m;
    if(n<=m){
        cout<<(n+1)<<endl;
        For(i,n+1){
            cout<<(n-i)<<" "<<i<<endl;
        }
    }else{
        cout<<(m+1)<<endl;
        For(i,m+1){
            cout<<i<<" "<<m-i<<endl;
        }
    }
  
    return 0;
}
