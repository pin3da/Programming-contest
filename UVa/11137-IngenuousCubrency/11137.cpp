using namespace std;
#include<iostream>
#include<cstring>

typedef long long int lli;

int main(){
	int cubes [22];
	for(int i=0;i<22;++i)cubes[i] = i*i*i;
	
	lli dp[10010];
	memset(dp,0,sizeof(dp));
	//for(int i=0;i<22;++i) dp[cubes[i]] = 1;
	dp[0] = 1;
	for(int i=1;i<22;++i){
		for(int j=0;j<=10000;++j){
			if(j+cubes[i] <= 10000)
				dp[j+cubes[i]] += dp[j];
		}
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}
