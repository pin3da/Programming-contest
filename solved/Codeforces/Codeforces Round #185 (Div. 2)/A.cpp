// http://codeforces.com/contest/312/problem/A

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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<ll> lucky;
void gen_lucky(ll a=0){
    if(a>1000000000L) return;
    ll x = (a*10) + 4;
    ll y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}

int main(){
    
    string cad;
    int num;getline(cin,cad);
    num = toInt(cad);
    while(num--){
        getline(cin,cad);
        if(cad.size()<5){
            cout<<"OMG>.< I don't know!"<<endl;
            continue;
        }
        string end = cad.substr(cad.size()-5);
        string start = cad.substr(0,5);
        //D(end);
        //D(start);
        if(start=="miao." and end == "lala."){
            cout<<"OMG>.< I don't know!"<<endl;
            continue;
        }
        if(end=="lala.")cout<<"Freda's"<<endl;
        else if(start == "miao.")cout<<"Rainbow's"<<endl;
        else cout<<"OMG>.< I don't know!"<<endl;
    }
    return 0;
    
}