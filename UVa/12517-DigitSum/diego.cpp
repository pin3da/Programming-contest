/**
* Solution by Diego A. España
*/

#include <stdio.h>
#include <string.h>

int M,N;
char MM[12],NN[12];


long long dp[11][2],dp1[11][2];

long long f1(int ind,char tope,int tam,char *cad){
  if (ind==tam)
    return 1;
  if (dp1[ind][tope]>=0)
    return dp1[ind][tope];
  if(tope==0){
    long long ret=0;
    int j;
    for(j=0;j<=9;j++)
      ret+=f1(ind+1,0,tam,cad);
    dp1[ind][tope]=ret;
    return ret;
  }
  long long ret=0;
  int j;
  for(j=0;j<=(cad[ind]-'0');j++)
    ret+=f1(ind+1,(cad[ind]-'0'==j)?1:0,tam,cad);
  dp1[ind][tope]=ret;
  return ret;
}

long long f(int ind,char tope,int tam,char *cad){

  if (ind==tam)
    return 0;
  if (dp[ind][tope]>=0)
    return dp[ind][tope];
  if(tope==0){
    long long ret=0;
    int j;
    for(j=0;j<=9;j++)
      ret+=f(ind+1,0,tam,cad)+j*f1(ind+1,0,tam,cad);
    dp[ind][tope]=ret;
    return ret;
  }
  long long ret=0;
  int j;
  for(j=0;j<=(cad[ind]-'0');j++){
    long long tt=f(ind+1,(cad[ind]-'0'==j)?1:0,tam,cad);
    long long ttt=j*f1(ind+1,(cad[ind]-'0'==j)?1:0,tam,cad);
    ret+=tt + ttt;
   }
  dp[ind][tope]=ret;
  return ret;
}

void clear(){
  int i;
  for(i=0;i<11;i++){
    dp[i][0]=-1;
    dp[i][1]=-1;
    dp1[i][0]=-1;
    dp1[i][1]=-1;
  }
}


int main(){
  while(1){
    scanf("%d %d",&M,&N);
    if (N==0 && M==0) break;
    M--;
    sprintf(MM,"%d",M);
    sprintf(NN,"%d",N);
    clear();
    long long a=f(0,1,strlen(MM),MM);
    clear();
    long long b=f(0,1,strlen(NN),NN);
    printf("%lld %lld \n",a,b);
    
  }
  return 0;
}

