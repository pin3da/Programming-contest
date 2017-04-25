// http://codeforces.com/contest/56/problem/B

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
    int c;cin>>c;
    vector<int> todo(c);
    vector<int> bien(c);
    int pin = 1;
    For(i,c){
        cin>>todo[i];
        bien[i]= todo[i]==i+1;
        pin &= bien[i];
    }
    if((!bien[0] and !bien[c-1] and bien[0]!=c and bien[c-1]!=1 and c!=2) or pin){
        cout<<"0 0"<<endl;
    }else{
        int i,j;
        for(i=0;bien[i];++i);
        for(j=c-1;bien[j];--j);
        int inicial = i+1;
        int posible = 1;
        for(int k=j;k>=i;--k){
            posible &= todo[k]==inicial;
            inicial++;
        }
        if(posible)
            cout<<i+1<<" "<<j+1<<endl;
        else
            cout<<"0 0"<<endl;
    }
    return 0;
}