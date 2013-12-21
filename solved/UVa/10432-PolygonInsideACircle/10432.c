#include<stdio.h>
#include<math.h>

int main(){
	double r,n,ans,pi=acos(-1);
	while(scanf("%lf %lf",&r,&n)==2){
		printf("%.3lf\n",n*r*r*0.5*sin((double)2.0*pi/n));
	}
	return 0;
}
