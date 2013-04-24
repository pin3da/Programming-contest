using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 2000

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

int primes[MP];
int sieve[MP];

void gen_primes(){
	memset(sieve,0,sizeof(sieve));
	sieve[0]=1;
	sieve[1]=1;
	For(i,MP){
		if(!sieve[i]){
			for(int j = i*i;j<MP;j+=i) sieve[j]=1;
		}
	}
}

int main(){	
	int a,b;
	gen_primes();
	while(cin>>a>>b and a+b){
		int ans =0;
		for(int i=a;i<=b;++i){
			if(!sieve[i])ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}
