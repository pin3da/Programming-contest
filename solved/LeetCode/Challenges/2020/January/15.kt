class Solution {
  fun getMaximumGenerated(n: Int): Int {
    if (n <= 1) {
      return n
    }
    var nums = Array<Int>(n+1) {0}
    nums[1] = 1
    nums[2] = 1
    for (i in 1..n) {
      var next = 2 * i
      if (next <= n) {
        nums[next] = nums[i]
      }
      next++
      if (next <= n) {
        nums[next] = nums[i] + nums[i + 1]
      }
    }
    return nums.max() ?: 0
  }
}
