class Solution {
  private var seen = Array(1001) { Array(1001) {-1} }
  
  private fun isPalindrome(s: String, i: Int, j: Int): Boolean {
    if (j <= i) {
      return true
    }
    if (seen[i][j] != -1) {
      return seen[i][j] == 1
    }
    if (s[i] == s[j] && isPalindrome(s, i + 1, j - 1)) {
      seen[i][j] = 1
      return true
    }
    seen[i][j] = 0
    return false
  }
  
  fun longestPalindrome(s: String): String {
    var maxLen = 0
    for (i in s.indices) {
      for (j in i until s.length) {
        if (isPalindrome(s, i, j)) {
          maxLen = maxLen.coerceAtLeast(j - i)
        }
      }
    }
   for (i in s.indices) {
      for (j in i until s.length) {
        if (isPalindrome(s, i, j) && (j - i) == maxLen) {
          return s.substring(i, j + 1)
        }
      }
    }
   error("answer not found.")
  }
}
