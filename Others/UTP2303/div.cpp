//*****         Big Number division         *********************// 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 
#define MAX 500000 
/*******************************************************************/ 
int call_div(char *number,long div,char *result){ 
 int len=strlen(number); 
 int now; 
 long extra; 
 char Res[MAX]; 
 for(now=0,extra=0;now<len;now++){ 
  extra=extra*10 + (number[now]-'0'); 
  Res[now]=extra / div +'0'; 
  extra%=div; 
 } 
 Res[now]='\0'; 
 for(now=0;Res[now]=='0';now++); 
 strcpy(result, &Res[now]); 
 if(strlen(result)==0) 
  strcpy(result, "0"); 
 return extra; 
} 
/*******************************************************************/ 
int main(){ 
    const int LIMIT = 20000;

    int sieve[LIMIT + 1]; // Inicializar con 0's.
    int primes[LIMIT + 1];
    
    int primeCount = 1;
    for (int i = 2; i <= LIMIT; ++i) {
      if (!sieve[i]) {
        primes[primeCount] = i;
        sieve[i] = primeCount;
        primeCount++;
      }
    
      for (int j = 1; j <= sieve[i] && i * primes[j] <= LIMIT; j++){
        sieve[ i * primes[j] ] = j;
      }
    }
    
    
    
    
    char fir[MAX],res[MAX]; 
    long sec,remainder; 
    int it,sol=0;
    while(scanf("%s",&fir)==1){ 
        //for(int i=0;i<strlen(fir);i++) printf("%c",fir[i]); 
       // printf("\n");
        for(it=1;it<primeCount;it++){
            remainder=call_div(fir,primes[it],res);
            if(remainder==0)break;
        }   
        while(1){
            call_div(fir,primes[it],res);
            sol++;
            memcpy(fir,res,strlen(res)+1);
            if(strcmp("1",fir)==0)break;
        }
        printf("%d %d\n",primes[it],sol);
        sol=0;
    } 
    return 0; 
} 
