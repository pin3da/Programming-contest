#include<stdio.h>
#define M 4000000

int fib[M];

int main(){
	int pos=1,it;
	long res=0;
	fib[0]=1;
	fib[1]=2;
	for(pos=2;;pos++){
		fib[pos]=fib[pos-1]+fib[pos-2];
		if(fib[pos]>M)break;
	}
	
	for(it=0;it<pos;it++)res+=fib[it],printf("%li\n",fib[it]);
	printf("%li\n",res);
	return 0;
}
