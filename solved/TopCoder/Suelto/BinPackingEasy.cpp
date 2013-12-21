// Wrong answer

using namespace std;
#include<bits/stdc++.h>


class BinPackingEasy {
	public:
	int minBins(vector <int> item) {
        int ans = 0;
        for(int i = 0; i< item.size(); ++i)
            if(item[i] >= 200) ans++;
            
        int quedan = item.size() - ans;
        
        quedan  = (quedan + 1) / 2;
        return ans + quedan;
	}
	
};
