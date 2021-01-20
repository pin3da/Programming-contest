class Solution {
  var state = 0
  val matcher = mapOf(
    '(' to ')',
    '{' to '}',
    '[' to ']'
  )
  
  fun isValid(s: String): Boolean {
    return parse(s) && state == s.length
  }
  
  fun parse(s: String): Boolean {
    if (state >= s.length) return true
    val cur = s[state]
    if (cur !in matcher.keys) return true
    state++
    val next = parse(s)
    if (!next || state >= s.length) return false
    if (matcher[cur] != s[state]) return false;
    state++
    return parse(s)
  }
}
