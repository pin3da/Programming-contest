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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


int main(){
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    int used = 0, ans = 0;
    int i= 0,j=0;
    while(used<n){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            i++;
        }
        if(i==a.size()){
            used++;
            i = 0;
        }
        if(j==b.size()){
            ans++;
            j = 0;
        }
    }
    cout<<ans/m<<endl;
    return 0; 
}
