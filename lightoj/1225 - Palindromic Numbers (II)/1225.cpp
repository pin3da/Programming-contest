#include<bits/stdc++.h>

char buffer[100];

int main(){
    int tc;scanf("%d",&tc);
    for(int tid = 1; tid <=tc; ++tid){
        scanf("%s",buffer);	
        int p = 1;
        int s = strlen(buffer);
        int s2 = s>>1;
        for(int i = 0; i< s; ++i)
            if(buffer[i] != buffer[s-i-1]){
                p = 0;
                break;
            }
            
        if(p) printf("Case %d: Yes\n", tid);
        else printf("Case %d: No\n", tid);

    }
    return 0;
}
