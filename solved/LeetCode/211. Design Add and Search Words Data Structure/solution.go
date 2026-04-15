package leetcode211

type trieNode struct {
	children [26]*trieNode
	isEnd    bool
}

type WordDictionary struct {
	root *trieNode
}

func Constructor() WordDictionary {
	return WordDictionary{root: &trieNode{}}
}

func (this *WordDictionary) AddWord(word string) {
	node := this.root
	for i := range word {
		idx := word[i] - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &trieNode{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	if len(word) == 0 {
		return false
	}
	var dfs func(node *trieNode, i int) bool
	dfs = func(node *trieNode, i int) bool {
		if i == len(word) {
			return node.isEnd
		}
		c := word[i]
		if c == '.' {
			for _, child := range node.children {
				if child != nil && dfs(child, i+1) {
					return true
				}
			}
			return false
		}
		idx := c - 'a'
		if node.children[idx] == nil {
			return false
		}
		return dfs(node.children[idx], i+1)
	}
	return dfs(this.root, 0)
}
