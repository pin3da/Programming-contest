        int n = nums.size();
        vector<int64> r(n);
        int64 size = 0;
        for (int i = n - 1; i >= 0; i--) {
            size += nums[i];
            r[i] += size;
            if (i + 1 < n) r[i] += r[i + 1];
        }


        size = 0;
        int64 prev = 0;
        int64 best = numeric_limits<int64>::max();
        for (int i = 0; i < n; i++) {
            best = min(best, prev + r[i]);
            size += (nums[i]);
            prev += size;
        }
        return best;