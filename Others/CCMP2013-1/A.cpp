using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define D(x) cout<< #x " = "<<(x)<<endl

struct candy{
	int p,c;
	candy(){}
	candy(int P,int C):c(C),p(P){}
};

int main(){
	int n,c;
	double m,p;
	while(cin>>n>>m){
		if(n==0 and m==0.0) break;
		vector<candy> todos(n);
		for(int i=0;i<n;++i){
			cin>>c>>p;
			todos[i].c = c;
			todos[i].p = (int)round(p*100);
		}
		int tengo = (int)round(m*100);
		int dp[tengo+1];
		dp[0] = 0;
		for(int i = 0;i<=tengo;++i){
			int mm = 0;
			for(int j = 0; j<n ;++j)
				if(i - todos[j].p >= 0 )
					mm = max(mm, dp[i-todos[j].p] + todos[j].c);
			
			dp[i] = mm;
		}
		cout<<dp[tengo]<<endl;
			
	}
	return 0;
}
