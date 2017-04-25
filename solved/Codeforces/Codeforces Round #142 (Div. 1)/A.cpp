// http://codeforces.com/contest/229/problem/A

using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cmath>
#include<cstdio>

#define For(i,n) for(int i=0;i<(n); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)

int main(){
	int n,m;
	cin>>n>>m;
	int dist[n][m];
	string cad;cad.reserve(m);
	For(i,n){
		cin>>cad;
		size_t pos = cad.find('1');
		if(pos==string::npos){
			cout<<-1<<endl;
			return 0;
		}
		int p=0;
		For(j,m){
			p = (cad[(pos+j)%m]=='1')?0:p+1;
			dist[i][(pos+j)%m]=p;
		}
		for(int j=m;j>0;--j){
			p = (cad[(pos+j)%m]=='1')?0:p+1;
			dist[i][(pos+j)%m] = min(dist[i][(pos+j)%m],p);
		}

	}
	int ans = (1<<30);
	For(i,m){
		int sum = 0;
		for (int j = 0; j < n; j++){
			sum += dist[j][i];
		}
       	ans = min(ans, sum);
    }

    cout << ans << endl;	
	return 0;
}

