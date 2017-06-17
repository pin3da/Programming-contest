package main

import "fmt"

func solve() {
	var u, v int64
	fmt.Scan(&u, &v)
	diag := u + v + 1
	best := (diag * (diag + 1)) >> 1
	fmt.Println(best - v)
}

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		solve()
	}
}
