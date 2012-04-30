using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_double 1.79769e+308
#define FILE_IN "multiply"

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
	return (x <= y + tol) ? ( x+ tol < y) ? -1 : 0 : 1;
}

typedef pair<double, double > pdd;
typedef long long ll;

int lengthInt(ll a){
	int r=0;
	while(a>0){
		a/=10;
		r++;
	}
	return r;
}

int myPrint(ll a, int delay){
	while(delay--)printf(" ");
	printf("%lld\n",a);
}

int val(ll a){
	int r=0;
	while(a>10){
		r+=a%10;
		a/=10;		
	}
	return r;
}

int main(){
	freopen(FILE_IN ".in","r",stdin);
	ll a,b,c;
	int la,lb,lc,sp,id=0,iter=0,num,k;
	while(true){
		cin>>a>>b;
		if(a==b and a==0)break;
		int band = val(b);
		c = a*b;
		num = b;
		sp = lc = lengthInt(c);
		la = lc - lengthInt(a);
		lb = lc - lengthInt(b);
		printf("Problem %d\n",++id);
		myPrint(a,la);
		myPrint(b,lb);
		if(band){
			for(int i=0;i<sp;++i)printf("-");
			printf("\n");
			iter=0;
			k=1;
			while( num > 0){
				ll tmp = num%(10);
				if(tmp==0){
					k*=10;
					iter++;
					num/=10;
					continue;
				}else{
					tmp*=(a);
					int ltmp = lc - lengthInt(tmp);
					myPrint(tmp*k,ltmp - iter);
					k=1;
					iter++;
					num/=10;
				}
			
			}
		}
		while(sp--)printf("-");
		printf("\n");
		printf("%lld\n",c);
	}
	return 0;
}
