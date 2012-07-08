
#include <cstdio>
#include <cstdlib>
#include <map>
#include <list>

#define rep(i,n) for (int i=0; i<(n); i++)

using namespace std;

map<int,int> visited;

int encode(int *st) {
    int ans=st[0] + 100*st[1] + 10000*st[2];
    return ans;
}

void decode(int st, int *ans) {
    ans[0] = st%100;
    ans[1] = (st/100) % 100;
    ans[2] = (st/10000);
}

int getChild(int state, int *children) {
    int st[3];
    int st2[3];
    int nch=0;
    decode(state,st);
    rep(i,3) {
        rep(j,3) {
            if (i!=j && st[i]>=st[j]) {
                rep(k,3) st2[k]=st[k];
                st2[i] -= st2[j];
                st2[j] *= 2;
                children[nch++] = encode(st2);
            }
        }
    }
    return nch;
}

bool bfs(int org, int dest) {
    visited.clear();
    list<int> q;    
    int child[9];
    int nch;
    q.push_front(org);
    visited[org] = -1;
    while (!q.empty()) {
        int act = q.back();
        if (act == dest) {
            return true;
        }
        q.pop_back();
        nch = getChild(act, child);
        rep(i,nch) {
            if (visited.count(child[i]) == 0) {
                q.push_front(child[i]);
                visited[child[i]] = act;
            }
        }
    }   
    return false; 
}

void test1() {
    int st;
    int ch[9];
    int n;
    scanf("%d",&st);
    n = getChild(st,ch);
    rep(i,n) printf("%d\n",ch[i]);
}

void printSt(int* st) {
    printf("%4d%4d%4d\n",st[0],st[1],st[2]);
}

int buffer[300000];
const char *barra = "============";

int main() {
    int st1[3],st2[3];
    int org,dest,sum;
    while (true) {
        scanf("%d %d %d",&st1[0],&st1[1],&st1[2]);
        if (st1[0]==0 && st1[1]==0 && st1[2]==0) {
            printSt(st1);
            printf("%s\n",barra);
            break;
        }
        org = encode(st1);
        sum = st1[0]+st1[1]+st1[2];
        if (sum%3 != 0) {
            printSt(st1);
            printf("%s\n",barra);
            continue;
        }
        rep(i,3) st2[i]=sum/3;
        dest = encode(st2);
        if (bfs(org,dest)) {
            int nmoves=0;
            int act = dest;
            while (act != -1) {
                buffer[nmoves++] = act;
                act = visited[act];
            }
            for (int i=nmoves-1; i>=0; i--) {
                decode(buffer[i],st2);
                printSt(st2);
            }
        } else {
            printSt(st1);
        }     
        printf("%s\n",barra);   
    }
}
