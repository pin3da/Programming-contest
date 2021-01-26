import kotlin.math.abs

class Solution {
  var group = IntArray(10100) { it }
  val deltaRow = intArrayOf(1, -1, 0, 0)
  val deltaCol = intArrayOf(0, 0, 1, -1)
  
  data class Edge(val from: Int, val to: Int, val cost: Int)
  
  fun minimumEffortPath(heights: Array<IntArray>): Int {
    val edges = mutableListOf<Edge>()
    for ((i, row) in heights.withIndex()) {
      for ((j, cell) in row.withIndex()) {
        for (k in deltaRow.indices) {
          val nI = i + deltaRow[k]
          val nJ = j + deltaCol[k]
          if (nI >= 0 && nI < heights.size && nJ >= 0 && nJ < row.size) {
            edges.add(Edge(
              getId(i, j),
              getId(nI, nJ),
              abs(cell - heights[nI][nJ])
            ))
          }
        }
      }
    }
    if (edges.size == 0) {
      return 0
    }
    edges.sortWith(compareBy { it.cost })
    val targetId = getId(heights.size - 1, heights[0].size - 1)
    var lastCost = 100000000
    for (e in edges) {
      if (getGroup(0) == getGroup(targetId)) {
        return lastCost
      }
      lastCost = e.cost
      joinNodes(e.from, e.to)
    }

    error("answer not found.")
  }
  
  private fun joinNodes(a: Int, b: Int) {
    group[getGroup(a)] = getGroup(b)
  }
  
  private fun getGroup(id: Int): Int {
    if (group[id] == id) {
      return id
    }
    group[id] = getGroup(group[id])
    return group[id]
  }
    
  private fun getId(i: Int, j: Int): Int {
    return i * 100 + j
  }
}
