class Solution {
  fun concatenatedBinary(n: Int): Int {
    var ans = 0
    val mod = 1000_000_007
    for (i in 1..n) {
      val binary = Integer.toBinaryString(i)
      for (bit in binary) {
        ans = (ans * 2) % mod
        if (bit == '1') {
          ans = (ans + 1) % mod
        }
      }
    }
    return ans
  }
}
