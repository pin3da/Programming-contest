#include<stdio.h>
#include<ctype.h>

int main(){
	char cad[30];
	int numcas,i,n;
	scanf("%d\n",&numcas);
	while(numcas--){
		gets(cad);
		printf("%s",cad);
		n=0;
        for(i=0;cad[i]!='\0';i++){
            if(tolower(cad[i])=='g')n++;
            if(tolower(cad[i])=='b')n--;
        }
        if(n==0)printf(" is NEUTRAL\n");
        if(n>0)printf(" is GOOD\n");
        if(n<0)printf(" is A BADDY\n");
	}
	return 0;
}
