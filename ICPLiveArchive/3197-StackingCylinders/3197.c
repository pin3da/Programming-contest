#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	double x;
	double y;
}pair;

pair mp[12][12];

pair f1(double ax,double ay){
	pair *a = (pair *) malloc(sizeof(pair));
	a->x=ax;
	a->y=ay;
	return *a;
}

pair f2(pair uno, pair dos){
	pair *a = (pair *) malloc(sizeof(pair));
	a->x =(uno.x+dos.x)/2.0;
	a->y= sqrt(4.0-pow((dos.x-uno.x)/2.0,2.0))+1.0;  
	return *a;
}
pair f3(pair uno, pair dos,pair tres){
	pair *a = (pair *) malloc(sizeof(pair));
	a->x = dos.x-(tres.x-uno.x);
    a->y=dos.y-(tres.y-uno.y);
	return *a;
}

int main(){
	int m,j,k;
	double tmp;
	while(1){
		scanf("%d",&m);
		if(m==0)break;
		for(j=0;j<m;j++){
			scanf("%lf",&tmp);
            mp[j][0] = f1(tmp,1.0);
		}
		k=1;
        while (k<m){
        	for (j = 0; j < m-k; j++) 
            	if(k==1)
                	mp[j][k] = f2(mp[j][k-1],mp[j+1][k-1]);
                else
                    mp[j][k] = f3(mp[j][k-1],mp[j+1][k-1],mp[j+1][k-2]);                  
             k++;
       	}
		printf("%.4lf %.4lf\n",mp[0][m-1].x,mp[0][m-1].y);
	}
	return 0;
}
