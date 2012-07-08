using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>


int main(){
	int s,d;
	while(scanf("%d %d",&s,&d)){
		if(s==-1 && d == -1)break;
		if(s>d){
			int t =s;
			s=d;
			d=t;
		}
		int b = fabs(d-s);
		int c = fabs(s-d +100);
		printf("%d\n",(c<b)?c:b);
	}
	return 0;
}
