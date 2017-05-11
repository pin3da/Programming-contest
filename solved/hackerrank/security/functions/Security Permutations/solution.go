package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var f = make([]int, n)
	for i := range f {
		fmt.Scan(&f[i])
		f[i]--
	}
	for i := range f {
		fmt.Println(f[f[i]] + 1)
	}
}
