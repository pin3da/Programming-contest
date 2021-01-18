class Solution {
  fun maxOperations(nums: IntArray, k: Int): Int {
    val freq = mutableMapOf<Int, Int>()
    var ans = 0
    for (i in nums) {
      val target = k - i
      if ((freq[target] ?: 0) > 0) {
        freq.put(target, freq[target]!! -1)
        ans++
      } else {
        freq[i] = (freq[i] ?: 0) + 1 
      }
    }
    return ans
  }
}
