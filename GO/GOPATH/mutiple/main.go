package main

import (
	"fmt"
	"runtime"
	"time"
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	for i := 0; i < 100; i++ {
		go asyncFunc(i)
	}

	sum := 0
	ch := make(chan int, 100)
	for i := 1; i <= 100; i++ {
		go func(data int, ch chan int) {
			ch <- data
		}(i, ch)
	}

	for i := 1; i <= 100; i++ {
		sum += <-ch
	}

	fmt.Println(sum)

	time.Sleep(2 * time.Second)
}

func asyncFunc(index int) {
	sum := 0

	for i := 1; i <= 100; i++ {
		sum += i
	}

	fmt.Printf("线程%d, sum = %d\n", index, sum)
}
