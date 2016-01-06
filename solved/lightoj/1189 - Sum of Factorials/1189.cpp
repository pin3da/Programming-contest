using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<limits>
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

template <class T> string toStr(const T &x){ stringstream s; s << x; return s.str(); }

typedef long long ll;
typedef unsigned int uint;

ll fac[22];
ll sum[22];

int pos[(1<<22)+1];

void gen_fac(){
	fac[0]=1;
	sum[0]=1;
	for(int i=0;i<22;++i){
		fac[i+1]= fac[i]*(i+1);
		sum[i+1]= sum[i] + fac[i+1];
	}
}

void gen_pos(){
	for(int i=0;i<=22;++i)
		pos[1<<i]=i;
	
}

void myprint(int a){
	if(a==0){
		cout<<"impossible"<<endl;
		return;
	}
	unsigned int w = a;
	string cad;
	while(w){
		cad+="+"+toStr(pos[(w & -w)>>1])+"!";
		w &= ~(w & -w);
	}
	cout<<cad.substr(1)<<endl;
}

int main(){
	gen_fac();
	gen_pos();
	int n;cin>>n;
	ll num;
	for(int i=1;i<=n; ++i){
		cin>>num;
		int ans = 0;
		int pos = 21;
		while(num && pos>=0){
			if(num >= fac[pos] and num- fac[pos] <= sum[pos -1]){
				ans = (1<<(pos+1)) | ans;
				num-= fac[pos];
			}
			pos--;
		}
		cout<<"Case "<<i<<": ";
		if(num>0){
			cout<<"impossible"<<endl;
			continue;
		}
		myprint(ans);
	}
	return 0;
}
