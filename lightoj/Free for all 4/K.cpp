/**

Edit distance from : http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B
*/

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
#define MP 1000000 
const double pi=acos(-1);

template <class T> unsigned int edit_distance(const T& s1, const T& s2)
{
        const size_t len1 = s1.size(), len2 = s2.size();
        vector<vector<unsigned int> > d(len1 + 1, vector<unsigned int>(len2 + 1));
 
        d[0][0] = 0;
        for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
        for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
 
        for(unsigned int i = 1; i <= len1; ++i)
                for(unsigned int j = 1; j <= len2; ++j)
 
                      d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
                                          d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 2) );
        return d[len1][len2];
}


int main(){
	int numcas;cin>>numcas;
	int cid=0;
	string a,b;
	while(numcas--){
		cin>>a>>b;
		cout<<"Case "<<++cid<<": "<<edit_distance(a,b)<<endl;
	}
	return 0;
}
