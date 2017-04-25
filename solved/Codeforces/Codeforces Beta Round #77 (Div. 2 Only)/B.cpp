// http://codeforces.com/contest/96/problem/B

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

int ct(lli b){
    string a= toStr(b);
    int ans=0;
    For(i,a.size())
        if(a[i]=='4')ans++;
        else ans--;
    return ans==0;
    
}

set<lli> lucky;
void gen_lucky(lli a=0){
    if(a>1000000000L) return;
    lli x = (a*10) + 4;
    lli y = (a*10) + 7;
    if(ct(x))
        lucky.insert(x);
    if(ct(y))
        lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}




int main(){
    gen_lucky();
    int k;cin>>k;
/*    foreach(v,lucky){
        cout<<(*v)<<endl;
    }*/
    cout<<(*lucky.lower_bound(k))<<endl;

}