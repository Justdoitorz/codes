package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan int)

	go func(c chan int) {

		for {
			data := <-c

			if data == 0 {
				break
			}

			fmt.Println(data)
		}

		c <- 0
	}(c)

	for i := 1; i <= 10; i++ {
		c <- i
	}

	c <- 0

	<-c

	var rch <-chan int = c
	var wch chan<- int = c

	go channlTest(rch)

	for i := 10; i >= 0; i-- {
		wch <- i
	}

	tch := make(chan int)
	quit := make(chan bool)
	go func() {
		for {
			select {
			case data := <-tch:
				fmt.Println(data)
			case <-time.After(3 * time.Second):
				fmt.Println("Time out")
				quit <- true
			}
		}
	}()

	for i := 0; i < 5; i++ {
		tch <- i
		time.Sleep(time.Second)
	}

	<-quit

	for i := 0; i < 5; i++ {
		go asyncFunc(i)
	}

	time.Sleep(5 * time.Second)
	//fmt.Println("Program end")
}

func asyncFunc(i int) {
	sum := 0
	for a := 0; a < 100; i++ {
		sum += a
	}

	fmt.Printf("线程%d， sum = %d\n", i, sum)
}

func channlTest(ch <-chan int) {
	for {
		data := <-ch

		if data == 0 {
			break
		}

		fmt.Println(data)
	}
}
