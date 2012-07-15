using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

typedef long long ll;

int main(){
	int numcas;cin>>numcas;
	int cas;
	ll n,m;
	while(numcas--){
		cin>>n>>m;
		cout<<"Case "<<++cas<<": ";
		if((n/m)%2==0)
			cout<<n*m/2<<endl;
		else
			cout<<(n+1)*(m/2)*(-1)<<endl;
	}

	return 0;
}
