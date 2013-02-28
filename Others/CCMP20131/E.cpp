using namespace std;
#include<iostream>
#include<vector>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#define For(i,n) for(int i=0;i<(n);++i)

vector<pair<int,int> > otros;

int main(){
	int n,w,l,h,area,m;
	while(cin>>n>>w>>l>>h>>area>>m and n+w+l+h+area+m !=0){
		otros.resize(m);
		For(i,m){
			cin>>otros[i].first>>otros[i].second;
		}
		int total = w*l;
		total += w*h*2 + l*h*2;
		For(i,m){
			total -= (otros[i].first * otros[i].second);
		}
		total *= n;
		double mio = total/(double)area;
		int ans = ceil(mio);
		cout<<ans<<endl;
	}
	return 0;
}
