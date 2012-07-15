using namespace std;
#include<iostream>
#include<cmath>

int main(){
	int	numcas;cin>>numcas;
	int n,cas=0;
	while(numcas--){
		cin>>n;
		int ans=0,t;
		while(n--){
			cin>>t;
			ans+=(t>0)?t:0;
		}
		cout<<"Case "<<++cas<<": "<<ans<<endl;
	}
	return 0;
}
