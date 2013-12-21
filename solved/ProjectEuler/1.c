#include<stdio.h>
#define M 1000

//266333
//544388

int main(){
	int res=0,i=1000;
	while(--i)
		if(i%3==0 || i%5==0)
			res+=i;
	printf("%d\n",res);
}
