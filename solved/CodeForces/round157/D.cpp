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
#define DET(a,b,c,d) ((a)*(d) - (b)*(c))
#define CRAMER(a,b,x,c,d,y) (DET(x,b,y,d)/DET(a,b,c,d))

typedef long long int lli;
const lli mod = 1000000007;
const lli fac6 = 720;

int cuantos[12];

int lucky(lli num){
    int ans=0LL;
    while(num){
        if(num%10LL == 4LL or num%10LL == 7LL) ans++;
        num= num/10LL;
    }
    return ans;
}


int fun(lli &num){
    int pin=-1;
    for(lli i=1LL;i<=num;i++){
        int m = lucky(i);
        pin= max(pin,m);
        cuantos[m]++;
    }
    
    return cuantos[pin];

}

lli fact(lli &num){
    lli ans = (lli)num;
    for(lli i=num-1;i>num-6;--i){
        ans = (ans*i)%mod;
    }
    return ans;

}



int main(){
    lli num;cin>>num;
    memset(cuantos,0,sizeof(cuantos));
    int mio = fun(num);
    num-= mio;
    cout<<mio*fact(num)<<endl;
	return 0;
}
