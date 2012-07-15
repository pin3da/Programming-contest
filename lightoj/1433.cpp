using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define For(i,n) for(long long i =0; i<n;++i)

typedef pair<double,double> pdd;

const double pi= acos(-1);

double angle(pdd a,pdd b,pdd c){
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	double r= acos((b.first * c.first + b.second * c.second) / (hypot(b.first, b.second) * hypot(c.first, c.second)));
	if(isnan(r))return acos(-1);
	return r;
}

double dist(pdd a,pdd b){
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x*x + y*y);
}

int main(){
	int numcas,cas=0;scanf("%d",&numcas);
	pdd o,a,b;
	while(numcas--){
		scanf("%lf %lf %lf %lf %lf %lf",&o.first,&o.second,&a.first,&a.second,&b.first,&b.second);
		printf("Case %d: %lf\n",++cas, dist(b,o)*angle(a,o,b));

	}
	return 0;
}
