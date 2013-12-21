/*
    Author       :  Jane Alam Jan 
    Problem Name :
    Algorithm    :
    Complexity   :
*/
 
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
// A = I + B/2 - 1
 
typedef long long i64;
 
struct point {
    i64 x, y;
}P[10001];
 
int ccw( point p0, point p1, point p2 ) {
    i64 dx1, dx2, dy1, dy2;
    dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
    if( dx1 * dy2 > dy1 * dx2 ) return +1;
    if( dx1 * dy2 < dy1 * dx2 ) return -1;
    if( dx1 * dx2 < 0 || dy1 * dy2 < 0 ) return -1;
    if( dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2 ) return +1;
    return 0;
}
 
// whether AB and CD intersects or not
bool intersect( point A, point B, point C, point D ) {
    return ccw( A, B, C ) * ccw( A, B, D ) <= 0 && ccw( C, D, A ) * ccw( C, D, B ) <= 0;
}
 
int main() {
    freopen("in", "w", stdout);
 
    double cl = clock();
 
    int cases = 100;
    printf("%d\n", cases);
    while( cases-- ) {
        int n = 10000 - rand() % 10;
        printf("%d\n", n);
 
        P[0].x = 0, P[0].y = 1000000;
 
        int L = 10000;
 
        for( int i = 1; i < n; i++ ) {
            P[i].x = P[i-1].x + rand() % 100 + 1;
            P[i].y = rand() % L;
        }
        P[n-1].y = 1000000;
        for( int i = 0; i < n; i++ ) printf("%lld %lld\n", P[i].x - 1000000, P[i].y);
    }
 
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
 
    return 0;
}
