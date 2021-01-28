class Solution {
  fun getSmallestString(n: Int, k: Int): String {
    val ans = IntArray(n) {1}
    var extra = k - n;
    for (i in ans.indices.reversed()) {
      val take = Math.min(extra, 25)
      ans[i] += take
      extra -= take
    }
    return ans.map {it -> (96 + it).toChar()}.joinToString(separator="")
  }
}
