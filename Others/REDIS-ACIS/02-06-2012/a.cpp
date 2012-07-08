
#include <cstdio>
#include <cstdlib>

#define rep(i,n) for (int i=0; i<(n); i++)

using namespace std;

int ans[600];
int org[600];
int n;

void insert(int val, int pos) {
    int i=0;
    while (true) {
        if (org[i] == 0){
            if (pos==0) break;
            pos--;
        }
        i++;
    }
    if (i>=n) throw "Out of bounds index exception";
    org[i] = val;
}

void getOrg() {
    rep(i,n) org[i]=0;
    rep(i,n) {
        insert(i+1,ans[i]);
    }
}

void printVec(int *v) {
    printf("%d",v[0]);
    for (int i=1; i<n; i++) {
        printf(",%d",v[i]);
    }
    printf("\n");
}

int main() {
    while (true) {
        scanf("%d",&n);
        if (n==0) break;
        rep(i,n) scanf("%d",&ans[i]);
        getOrg();
        printVec(org);
    }
}
