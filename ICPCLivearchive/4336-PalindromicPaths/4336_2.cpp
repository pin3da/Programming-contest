#include<cstdio>
#include<string>
using namespace std;
string st[100][100],tmp;
int len[100][100],i,j,k,l,m,t,n;
char d[100][100],ch;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%c",&ch);
            for(j=0;j<n;j++){
                scanf("%c",&ch);
                len[i][j]=0;
                st[i][j]="";
                if(i>=j) continue;
                len[i][j]=1;
                st[i][j]+=ch;
                d[i][j]=ch;
            }  
        }  
        for(k=1;k<n;k++){
            for(i=0;i<n;i++){
                if(i+k>=n) break;
                j=i+k;
                for(l=i+1;l<j;l++){
                    for(m=l;m<j;m++){
                        if(d[i][l]==d[m][j]){
                            tmp=d[i][l]+st[l][m]+d[m][j];
                            if(len[l][m]+2>len[i][j]){
                                len[i][j]=len[l][m]+2;
                                st[i][j]=tmp;  
                            }  
                            else if(len[l][m]+2==len[i][j] && st[i][j]>tmp) st[i][j]=tmp;     
                        }  
                    }
                }
            }  
        }
        printf("%s\n",st[0][n-1].c_str());
    }  
}
