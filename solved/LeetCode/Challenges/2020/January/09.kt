class Solution {
    fun ladderLength(beginWord: String, endWord: String, wordList: List<String>): Int {
        if (endWord !in wordList) {
            return 0
        }
        val valid = wordList.toSet()
        val inf = 10000
        val dist = mutableMapOf<String, Int>()
        for (w in wordList) {
            dist[w] = inf
        }
        dist[beginWord] = 1
        val q = ArrayDeque<CharArray>()
        q.add(beginWord.toCharArray())
        val target = endWord.toCharArray()
        while (q.isNotEmpty()) {
            val cur = q.removeFirst()
            val st = String(cur)
            val newDist = dist[st]!! + 1
            for (i in cur.indices) {
                val next = cur.copyOf()
                for (c in 'a'..'z') {
                    next[i] = c
                    if (next contentEquals target) {
                        return newDist
                    }
                    val stNext = String(next)
                    if (stNext in valid && newDist < dist.getOrDefault(stNext, inf)) {
                        dist[stNext] = newDist
                        q.add(next.copyOf())
                    }
                }
            }
        }
        return 0
    }
}
