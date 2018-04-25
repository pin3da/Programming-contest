class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int is_neg = n < 0;
        long long e = llabs(n);
        while (e > 0) {
            if (e & 1)
                ans *= x;
            x *= x;
            e >>= 1;
        }
        return is_neg ? 1.0/ans : ans;
    }
};
