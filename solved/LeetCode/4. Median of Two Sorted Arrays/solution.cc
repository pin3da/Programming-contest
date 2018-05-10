class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len = nums1.size() + nums2.size();
      set<int> need;
      if ((len & 1) == 0)
        need.insert((len - 1) / 2);
      need.insert((len) / 2);

      size_t i = 0, j = 0, seen = 0;
      long long sum = 0;
      while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] <= nums2[j]) {
          if (need.count(seen))
            sum += nums1[i];
          i++;
        } else {
          if (need.count(seen))
            sum += nums2[j];
          j++;
        }
        seen++;
      }
      while (i < nums1.size()) {
        if (need.count(seen))
          sum += nums1[i];
        i++;
        seen++;
      }
      while (j < nums2.size()) {
        if (need.count(seen))
          sum += nums2[j];
        j++;
        seen++;
      }
      return sum / double(need.size());
    }
};

