// http://codeforces.com/contest/49/problem/D

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
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;


int main(){
    int n;cin>>n;
    string cad;cin>>cad;
    int ans1 =0,ans2 = 0;
    For(i,n){
        if(i&1){
            ans1 += cad[i]=='0';
            ans2 += cad[i]=='1';
        }else{
            ans1 += cad[i]=='1';
            ans2 += cad[i]=='0';
        }
    }
    cout<<min(ans1,ans2)<<endl;
}