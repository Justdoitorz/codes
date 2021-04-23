package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("Channel Test")
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, -77}
	ch := make(chan int, 2)

	go sum(arr[len(arr)/2:], ch)
	go sum(arr[:len(arr)/2], ch)
	time.Sleep(time.Second)

	x, y := <-ch, <-ch
	fmt.Println("...")
	fmt.Println(x, y, x+y)
}

func sum(arr []int, ch chan int) {
	fmt.Println("sum start")
	sum := 0
	for _, v := range arr {
		sum += v
	}
	ch <- sum
	fmt.Println("sum end")
}
