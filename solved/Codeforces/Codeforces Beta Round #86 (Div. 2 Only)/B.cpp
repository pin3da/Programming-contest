// http://codeforces.com/contest/114/problem/B

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


map<string,int> cod;
map<int,string> decod;
int paila[20][20];

int valid(int s){
    For(i,20)
        For(j,20)
            if(s&(1<<i) and s&(1<<j))
                if(paila[i][j])
                    return 0;
    return 1;
}

void mpr(int s){
    cout<<__builtin_popcount(s)<<endl;
    set<string> ans;
    For(i,20)
        if(s&(1<<i))
            ans.insert(decod[i]);
            
    foreach(x,ans){
        cout<<(*x)<<endl;
    }
}

int main(){
    int cuantos,ene;cin>>cuantos>>ene;
    string name;

    int act=0;
    For(i,cuantos){
        cin>>name;
        cod[name] = act;
        decod[act++]= name;
        
    }

    memset(paila,0,sizeof(paila));
    For(i,ene){
        string p,q;cin>>p>>q;
        paila[cod[p]][cod[q]]=1;
        paila[cod[q]][cod[p]]=1;
    }
    int cc=0;
    int ans;
    for(int i=(1<<cuantos)-1;i>=0;--i){
        if(valid(i)){
            if(__builtin_popcount(i) > cc){
                ans = i;
                cc = __builtin_popcount(i);
            }
        }
    }
    mpr(ans);
    return 0;
    
    
}