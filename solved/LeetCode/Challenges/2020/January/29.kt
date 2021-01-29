class Solution {
  data class Entry(val x: Int, val y: Int, val value: Int)
  
  val entries = mutableListOf<Entry>()
  
  fun verticalTraversal(root: TreeNode?): List<List<Int>> {
      dfs(root, 0, 0)
      entries.sortBy { it.x }
      return entries.groupBy { it.x }.values
        .map{ it.sortedWith(compareBy({-it.y}, {it.value})) }
        .map { l -> l.map {it.value} }
  }
  
  fun dfs(root: TreeNode?, x: Int, y: Int) {
    if (root == null) {
      return
    }
    entries.add(Entry(x, y, root!!.`val`))
    dfs(root!!.left, x - 1, y - 1)
    dfs(root!!.right, x + 1, y - 1)
  }
}
