// http://codeforces.com/contest/300/problem/A

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
    int n;cin>>n;
    set<int> neg,pos,ceros;
    int tmp;
    For(i,n){   
        cin>>tmp;
        if(tmp<0)neg.insert(tmp);
        else if(tmp>0)pos.insert(tmp);
        else ceros.insert(tmp);
    }
    int pin= 0;
    if(neg.size()%2==0 or pos.size()==0){
        cout<<1<<" "<<(*neg.begin())<<endl;
        neg.erase(neg.begin());
    }else{
        cout<<neg.size()<<" ";
        foreach(xx,neg){
            cout<<(*xx)<<" ";
        }
        cout<<endl;
        pin =1;
    }
    if(!pin){
        if(neg.size()%2!=0){
            ceros.insert(*(neg.begin()));
            neg.erase(neg.begin());
        }
        cout<<neg.size()+pos.size()<<" ";
        foreach(x,neg)cout<<(*x)<<" ";
        foreach(x,pos)cout<<(*x)<<" ";
        cout<<endl;
    }else{
        cout<<pos.size()<<" ";
        foreach(x,pos) cout<<(*x)<<" ";
        cout<<endl;
    }
    cout<<ceros.size()<<" ";
    foreach(xx,ceros)cout<<(*xx)<<" ";
    cout<<endl;

    return 0;
    
}
