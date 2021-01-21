class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      auto ans = deque<int>();
      auto need = [&ans, &k] () {
        return k - ans.size(); 
      };
      ans.push_back(nums[0]);
      for (int i = 1; i < nums.size(); i++) {
        int rem = nums.size() - i;
        if (nums[i] > ans.back()) {
          if (ans.size() < k) {
            ans.push_back(nums[i]);
          }
          continue;
        }
        while (ans.size() > 0 && nums[i] < ans.back() && rem > need()) {
          ans.pop_back();
        }
        if (ans.size() < k) {
          ans.push_back(nums[i]);
        }
      }
      return vector<int>(ans.begin(), ans.end());
    }
};

/*
Kotlin code with TLE.

class Solution {
  fun mostCompetitive(nums: IntArray, k: Int): IntArray {
    val ans = ArrayDeque<Int>(nums.size) 
    val need = { k - ans.size }
    ans.addLast(nums[0])
    for (i in 1 until nums.size) {
      val rem = nums.size - i
      if (nums[i] > ans.last()) {
        if (ans.size < k) {
          ans.addLast(nums[i])
        }
        continue
      }
      while (ans.size > 0 && nums[i] < ans.last() && rem > need()) {
        ans.removeLast()
      }
      if (ans.size < k) {
        ans.addLast(nums[i])
      }
    }
    return ans.toIntArray()
  }
}
*/
