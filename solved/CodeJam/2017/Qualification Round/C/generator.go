package main

import (
	"fmt"
	"math/rand"
)

const N int64 = 1000000000000000000

func main() {
	tc := 1000
	fmt.Println(tc)
	for i := 0; i < tc; i++ {
		n := rand.Int63n(N)
		k := rand.Int63n(n)
		fmt.Println(n, k)
	}
}
