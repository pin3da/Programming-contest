// http://codeforces.com/contest/141/problem/B

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
    int a,b,c;cin>>a>>b>>c;
    if(c < a and fabs(b)*2 < a and c != 0){
        cout<<1<<endl;
        return 0;
    }
    if(c < 2*a and fabs(b)*2 < a  and c != a and c!= 2*a and c!=0){
        cout<<2<<endl;
        return 0;
    }    
    c-=2*a;
    if(c < 0 or c%a==0){
        cout<<-1<<endl;
        return 0;
    }
    int ans = c/a;
    if(ans%2==0){
        if(fabs(b) < a){
            if(b > 0)
                cout<<((((ans/2)+1)*3)+1)<<endl;
            else if(b < 0)
                cout<<(((ans/2)+1)*3)<<endl;
            else
                cout<<-1<<endl;
                
        }else{
            cout<<-1<<endl;
        }
    }else{
        if(2*fabs(b) < a){
            cout<<(((ans/2)*3)+5)<<endl;
        }else
            cout<<-1<<endl;
    }
    
        
    return 0;
}