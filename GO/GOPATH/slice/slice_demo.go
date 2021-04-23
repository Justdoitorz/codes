package main

import (
	"container/list"
	"fmt"
)

func main() {
	var slice [][]int

	slice = [][]int{{1}, {2, 3}}

	fmt.Println(slice)
	fmt.Printf("addr = %p\n", slice)
	fmt.Printf("slice[0] = %p\n", slice[0])
	fmt.Println(len(slice), cap(slice))
	slice = append(slice, []int{4, 5, 6})
	fmt.Println(slice)
	fmt.Printf("slice = %p\n", slice)
	fmt.Printf("slice[0] = %p\n", slice[0])
	fmt.Println(len(slice), cap(slice))
	slice[0] = append(slice[0], 0)
	fmt.Println(slice)
	fmt.Printf("addr = %p\n", slice)
	fmt.Printf("slice[0] = %p\n", slice[0])

	var mapList map[string]int
	//var mapAssigned map[string]int
	fmt.Println(mapList)
	fmt.Printf("mapList = %p\n", mapList)
	mapList = map[string]int{
		"one": 1,
		"two": 2,
	}

	fmt.Printf("mapList = %p\n", mapList)
	fmt.Printf("mapList[] = %T\n", mapList["one"])

	fmt.Println(mapList)
	fmt.Println(mapList["one"])
	fmt.Println(mapList["wtf"])

	l := list.New()
	l.PushBack("first")
	l.PushFront(67)
	fmt.Println(l)

	for i := l.Front(); i != nil; i = i.Next() {
		fmt.Println(i.Value)
	}

	element := l.PushBack("canon")

	l.InsertAfter("high", element)

	l.InsertBefore("noon", element)

	//l.Remove(element)

	for i := l.Front(); i != nil; i = i.Next() {
		fmt.Println(i.Value)
	}

	c := make(chan int)

	go func() {
		c <- 1
		c <- 2
		c <- 3
		close(c)
	}()

	for v := range c {
		fmt.Println(v)
	}

	var a = "mum"

	switch a {
	case "mum", "daddy":
		fmt.Println("family")
	}

	var r int = 11

	switch {
	case r >= 10 && r < 20:
		fmt.Println(r)
	}
}
