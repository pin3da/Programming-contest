using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
#define Dbg if(0)
#define MAXP 1000003

#define scanll(x) scanf("%lld",&x);
#define pll(x) printf("%lld",x);


int trees[MAXP];



int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i){
		scanf("%d", trees+i);
	}
	sort(trees,trees+n);
	int un = trees[n-1];
	int si = trees[0];
	int mid = (si+un)/2;
	long long sum;
	while(si<un){
		mid = (si + un +1)/2;
		sum = 0;
		for(int i=0; i<n; i++)
            sum += ((trees[i] - mid) > 0)? (trees[i] - mid):0;
		if(sum < m)
			un = mid - 1;
		else si = mid;
	}
	printf("%d\n",si);
	return 0;
}
