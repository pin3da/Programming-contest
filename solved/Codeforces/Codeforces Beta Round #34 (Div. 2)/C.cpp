// http://codeforces.com/contest/34/problem/C

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


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<lli> lucky;
void gen_lucky(lli a=0){
    if(a>1000000000L) return;
    lli x = (a*10) + 4;
    lli y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}


int main(){
    string buff;
    getline(cin,buff);
    For(i,buff.size()) if(buff[i]==',') buff[i] = ' ';
    int tmp;
    int todos[1010];
    memset(todos,0,sizeof(todos));
    stringstream ss(buff);
    while(ss>>tmp){
        todos[tmp] =  1;
    }
    int abre = 1;
    int l,r;
    int first = 1;
    For(i,1002){
        if(todos[i] and abre){
            l = i;
            abre = 0;
        }else if(!todos[i] and !abre){
            r = i-1;
            abre = 1;
            if(first) first=0;
            else cout<<",";
            if(l!=r)
                cout<<l<<"-"<<r;
            else
                cout<<l;
        }
    }
    cout<<endl;
    return 0;
    
}