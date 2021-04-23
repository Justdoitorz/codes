package main

import (
	"fmt"
	. "fmt" //should not use dot imports
	f "fmt"
	"math"
	"math/cmplx"
	"runtime"
	"strings"
	"time"

	//"code.google.com/p/go-tour/pic"

	"../module"
)

var (
	//ToBe ..
	ToBe bool = false
	//MaxInt ..
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

const (
	//Big ..
	Big = 1 << 100
	//Small ..
	Small = Big >> 99
)

func needInt(x int) int           { return x*10 + 1 }
func needFloat(x float64) float64 { return x * .1 }

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

//Sqrt ...
func Sqrt(x float64) float64 {
	z := float64(1)

	for ; math.Abs((z*z-x)/(2*z)) < 1e-8; z = z - (z*z-x)/(2*z) {
		fmt.Println("Die")
	}
	return z
}

//Pic ..
func Pic(dx, dy int) [][]int8 {
	z := make([][]int8, dy)
	for i := range z {
		z[i] = make([]int8, dx)
	}
	return z
}

//Vertex ...
type Vertex struct {
	Lat, Long float64
}

func main() {
	p := module.NewPerson("Fuck")
	p.SetAge(18)
	p.SetSal(6666)
	fmt.Println(p)
	Println("mdzz")
	f.Println(p.Name, " age = ", p.GetAge(), " sal = ", p.GetSal())
	//f.Println(p.getSal())

	fmt.Println(split(15))

	const f = "%T(%v)\n"
	fmt.Printf(f, ToBe, ToBe)
	fmt.Printf(f, MaxInt, MaxInt)
	fmt.Printf(f, z, z)

	fmt.Println(Small)
	//fmt.Println(Big)
	fmt.Println(needInt(Small))
	//fmt.Println(needInt(Big))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))

	fmt.Println(Sqrt(2))
	fmt.Println(math.Sqrt(2))

	fmt.Println(runtime.GOOS)
	fmt.Println(time.Now().Weekday())

	defer fmt.Println("World")
	defer fmt.Println("WTF")
	fmt.Println("Hello")

	pow := make([]int, 10)
	for i := range pow {
		pow[i] = 1 << uint(i)
	}

	for _, value := range pow {
		fmt.Println(value)
	}

	//pic.Show(Pic)

	slice := Pic(2, 4)

	fmt.Println(len(slice), cap(slice))
	fmt.Println(len(slice[0]), cap(slice[1]))

	m := make(map[string]Vertex)

	m["Xiamen"] = Vertex{
		24.48537058265533, 118.18333904212955,
	}

	fmt.Println(m["Xiamen"])
	v, ok := m["Answer"]
	fmt.Println("The value:", v, "Present?", ok)
	var s string = "I love you do you like me "
	ss := strings.Fields(s)
	var msi = make(map[string]int)
	for _, v := range ss {
		msi[v]++
	}
	fmt.Println(msi)

	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}

	fmt.Println(hypot(3, 4))

	pos, neg := adder(), adder()

	for i := 0; i < 10; i++ {
		fmt.Println(pos(i), neg(-2*i))
	}
	fib := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(fib())
	}
}

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func fibonacci() func() int {
	a, b := 0, 1
	return func() int {
		a, b = a+b, a
		return a
	}
}
