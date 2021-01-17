class Solution {
  data class State(val n: Int, val last: Int)
  val seen = mutableMapOf<State, Int>()
  
  fun countVowelStrings(n: Int): Int {
    return count(State(n, 0))
  }
  
  private fun count(s: State) : Int {
    if (s.n == 0) {
      return 1
    }
    
    if (seen.contains(s)) {
      return seen[s]!!
    }
    
    var ans = 0
    for (next in s.last..4) {
      ans += count(State(s.n-1, next))
    }
    seen[s] = ans
    return ans
  }
}
