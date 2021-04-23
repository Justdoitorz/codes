package main

import (
	"flag"
	"fmt"
	"math"
)

func main() {
	fmt.Println("func demo")
	flag.Parse()
	for _, v := range flag.Args() {
		fmt.Println(v)
	}

	fmt.Println(hypot(8, 15))

	fmt.Println(add(1, 2))
	fmt.Println(sub(1, 2))
	fmt.Println(first(1, 2))
	fmt.Println(zero(1, 2))

	fmt.Println(retname())
	fmt.Println(retnameEx())

	f := retname
	fmt.Println(f())
	func(data int) {
		fmt.Println(data)
	}(100)

	g := func(data int) {
		fmt.Println(data)
	}
	g(1024)

	visit([]int{1, 2, 3}, func(v int) {
		fmt.Println(v)
	})

	var skill = map[string]func(){
		"fire": func() {
			fmt.Println("Chicken fire")
		},
		"run": func() {
			fmt.Println("soldier run")
		},
		"fly": func() {
			fmt.Println("angel fly")
		},
	}

	if f, ok := skill[*skillParam]; ok {
		f()
	} else {
		fmt.Println("skill not found:", *skillParam)
	}

	fmt.Println(*intParam)

	var b int8 = 11
	var c int = 12
	var p *int

	c = (int)(b)
	fmt.Println(c)
	fmt.Println(*p)

}

var skillParam = flag.String("skill", "default", "skill to perform")
var intParam = flag.Int("inputvalue", 123456, "integer")

func hypot(x, y float64) float64 {
	return math.Sqrt(x*x + y*y)
}

func add(x, y int) int      { return x + y }
func sub(x, y int) int      { return x - y }
func first(x, _ int) int    { return x }
func zero(_, _ int) int     { return 0 }
func retname() (a, b int)   { a = 4; b = 6; return }
func retnameEx() (a, b int) { a = 4; b = 6; return 1, 2 }

func visit(list []int, f func(int)) {
	for _, v := range list {
		f(v)
	}
}
