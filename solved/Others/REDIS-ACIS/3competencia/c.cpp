#include<stdio.h>

int main(){
	long a,b,c,d,e;
	while(true){
		scanf("%li %li %li %li %li",&a,&b,&c,&d,&e);
		if(a ==0 && b ==0 && c ==0 && d==0 && e ==0)break;
		printf("%li\n",a*b*c*d*d*e*e);
	}
	return 0;
}
