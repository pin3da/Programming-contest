/*	Manuel Pineda.
	No accepted yet.
	four point in a paralelogram.
				  2
    			 /
				/		
		1-----3/
	  4 = 2 -(3 - 1);
	the point 3 is the repeated point
*/
#include<stdio.h>
int main(){
	int i,j;
	double p[8];
	double r1x,r2x,r3x,r1y,r2y,r3y,a1,a2;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n",p,p+1,p+2,p+3,p+4,p+5,p+6,p+7)==8){
		for(i=0;i<8;i+=2)
			for(j=i+2;j<8;j+=2)
				if(p[i]==p[j]){
					r3x=p[i];
					r3y=p[i+1];
					break;
				}
		 for(i=0;i<8;i+=2)
			if(p[i]!=r3x){
				r2x=p[i];
				r2y=p[i+1];
			}
		 for(i=6;i>=0;i-=2)
			if(p[i]!=r3x){
				r1x=p[i];
				r1y=p[i+1];
			}
		a1=r2x-(r3x-r1x);
		a2=r2y-(r3y-r1y);
		printf("%.3lf %.3lf\n", a1,a2);
	}
	return 0;
}

