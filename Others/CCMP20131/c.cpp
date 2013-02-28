using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#define D(x) cout<< #x " = "<<(x)<<endl

typedef long long int lli;

bool my_cmp(pair<double, double> a, pair<double, double> b){
	return a.first*b.second < b.first*a.second;
}

int main(){
	double a,b,n,m1;
	while(cin>>b>>n and b+n){
		vector< pair<double,double> > ans;
		for(int m=1;m<=2000000;++m){
			if(m==n)continue ; //division por cero
			m1 = (double)m;
			a = ((2.0*b*m1)/n) - ((b*m*m)/(n*n));
			if(a - (lli)a < 1e-9 and a>0.0) ans.push_back(make_pair(a,m));
		}
		sort(ans.begin(),ans.end(),my_cmp);
		
		lli mio = 2LL*n;
		printf("0/%lld",mio);
		if(ans.size()!=0)printf(" ");
		else printf("\n");
		for(int i=0;i<ans.size();++i){
			printf("%lld/%lld%c",(lli)ans[i].first,(lli)ans[i].second,((i==ans.size()-1)?'\n':' '));
		}
	}
	return 0;
}

