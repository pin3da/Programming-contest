#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))

const int NUM=100005;
const double STD=1e-12;
const double PI=acos(-1.0);
typedef long long int int64;
struct Point
{
    int64 x,y;

	void get ()
	{
		scanf("%lld%lld",&x,&y);
    }

	void output ()
	{
		printf("%lld %lld\n",x,y);
	}
    bool operator < (const Point& _P) const
    {
        return y<_P.y||(y==_P.y&&x<_P.x);
    }

	Point friend Vec (Point a,Point b)   //构造向量ba
    {  
        Point res;  
        res.x=a.x-b.x;  
        res.y=a.y-b.y;  
        return res;  
    } 
}pt[NUM],ch[NUM];

int n,len;
  
int64 cross (Point p,Point q,Point x)
{
	return (p.x-x.x)*(q.y-x.y)-(q.x-x.x)*(p.y-x.y);
}

//ch[0]~ch[len-1]保存凸包,只保存顶点
//pt[]为源数据,n为原点数
void Graham (Point pt[],Point ch[],int &len,int n)
{
	int i,top=1;
    sort(pt,pt+n);
    ch[0]=pt[0];
    ch[1]=pt[1];
    for (i=2;i<n;i++)
    {
        while (top>0 && cross(ch[top],pt[i],ch[top-1]) <= 0)
            top--;
        ch[++top]=pt[i];
    }
    int temp=top;
    for (i=n-2;i>=0;i--)
    {
        while (top>temp && cross(ch[top],pt[i],ch[top-1]) <= 0)
            top--;
        ch[++top]=pt[i];
    }
    len=top;    
}

double get_dis (Point a,Point b)        //计算两点间距离  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}

int64 get_cj (Point a,Point b)        //计算叉积
{  
    return a.x*b.y-a.y*b.x;
}  
  
int64 get_dj (Point a,Point b)        //计算点积
{  
    return a.x*b.x+a.y*b.y;  
}

double Cal_Alpha (Point c,Point a,Point b)     //计算扇形面积  
{	
	double da=get_dis (a,c);
	double db=get_dis (b,c);
	int64 cj=get_cj (Vec(a,c),Vec(b,c));
	int64 dj=get_dj (Vec(a,c),Vec(b,c));  
    double dsin=cj/(da*db);
    double alpha=asin(dsin);  
  
   //asin函数求出的角是0到90度的,需要根据实际情况还原到原来的大小
    if (dj < 0)           //当夹角大于90度时  
            alpha=PI-alpha;  
    return alpha*180/PI;
}
 
/*另一种求角度的方法
double Cal_Alpha (const Point &o, const Point &a, const Point &b)
{
	Point t1,t2;
	double theta;
	t1.x = a.x - o.x, t1.y = a.y - o.y;
	t2.x = b.x - o.x, t2.y = b.y - o.y;
	theta = atan2((double)t2.y, (double)t2.x) - atan2((double)t1.y, (double)t1.x);
	if (theta < -STD)
		theta += 2.0 * PI;
	return theta*180/PI;
}*/

double Deal ()    //len为顶点数
{
	int i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		pt[i].get();
	Graham (pt,ch,len,n);
	if (len < 3)
		return 0;
	double ans=180;
	for (i=0;i<len;i++){
		/*ch[i].output();
		ch[(i+1)%len].output();
		ch[(len+i-1)%len].output();*/
		ans=min(ans,(Cal_Alpha (ch[i],ch[(i+1)%len],ch[(len+i-1)%len])));
//		printf("t = %.8lf\n",Cal_Alpha (ch[i],ch[(i+1)%len],ch[(len+i-1)%len]));
	}
	return ans;
}

int main ()
{
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
		printf("Case %d: %.8lf\n",cas,Deal());
	return 0;
}
