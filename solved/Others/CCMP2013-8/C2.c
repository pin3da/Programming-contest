#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char cad[100010];
    int a,b,q,tam;
    int ans;
    while(scanf("%s",cad)){
        if(cad[0]=='*')break;
        scanf("%d",&q);
        tam = strlen(cad);
        while(q--){
            scanf("%d %d",&a,&b);
            ans = 0;
            while(cad[a] ==cad[b] && b < tam){
                ans++;
                a++;
                b++;
            }
            printf("%d\n",ans);
        }
        
    }
    return 0;
}

