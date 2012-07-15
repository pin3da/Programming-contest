using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>
#define ifd if(0)

typedef long long ll;

int main(){
	int numcas;cin>>numcas;
	ll n,x,y,cas=0;
	while(numcas--){
		cin>>n;
		double m = ceil(sqrt(n));
		ll d = m*m -n;
		if(d<m){
			y=m;
			x=d+1;
		}else{
			x=m;
			y=n-(m-1)*(m-1);
		}
		if((int)m%2==0){
			ll t=x;
			x=y;
			y=t;
		}
		cout<<"Case "<<++cas<<": "<<x<<" "<<y<<endl;
	}
	return 0;
}
