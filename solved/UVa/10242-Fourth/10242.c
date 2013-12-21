/*	Manuel Pineda.
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
	double x1,x2,x3,x4,y1,y2,y3,y4,a1,a2;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==8){
		if(x1==x2 && y1==y2){
			a1=x4-(x1-x3);
			a2=y4-(y1-y3);
		}else if(x1==x3 && y1==y3){
			a1=x2-(x1-x4);
			a2=y2-(y1-y4);
		}else if(x1==x4 && y1==y4){
			a1=x3-(x1-x2);
			a2=y3-(y1-y2);
		}else if(x2==x3 && y2==y3){			
			a1=x1-(x2-x4);
			a2=y1-(y2-y4);
		}else if(x2==x4 && y2==y4){			
			a1=x3-(x2-x1);
			a2=y3-(y2-y1);
		}else if(x3==x4 && x3==x4){			
			a1=x1-(x3-x2);
			a2=y1-(y3-y2);
		}
		printf("%.3lf %.3lf\n", a1,a2);
	}
	return 0;
}

