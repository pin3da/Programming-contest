#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define pp 1e-6
using namespace std;
struct node
{
    double x,y;
    int num;
}link[10010];
int cmp(node a,node b)
{
    double qq;
    qq=(a.y-link[0].y)*(b.x-link[0].x)-(b.y-link[0].y)*(a.x-link[0].x);
    return qq>pp;
}
int main()
{
    int n,p,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%lf%lf",&link[i].x,&link[i].y);
    link[i].num=i+1;
    }
    p=0;
    for(i=1;i<n;i++)
    if(link[i].x<link[p].x||(link[i].x==link[p].x&&link[i].y<link[p].y))
    p=i;
    swap(link[0],link[p]);
    sort(link+1,link+n,cmp);
     printf("%d %d\n",link[0].num,link[n/2].num);
     return 0;
}
