class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (mid * mid > x)
                hi = mid - 1;
            else
                lo = mid;
        }
        return lo;
    }
};
