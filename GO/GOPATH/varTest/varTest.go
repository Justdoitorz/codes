package main

import (
	"fmt"
	"unsafe"
)

func main() {
	fmt.Println("bitch")
	var age int
	fmt.Scanf("%d", &age)
	fmt.Println(age)
	var str string = "Hello, Tady"
	fmt.Println(str)

	var a, b int = 1, 3

	fmt.Println(a, b)

	var strNoInit string
	var intNoInit int
	var boolNoINit bool

	fmt.Println(strNoInit, intNoInit, boolNoINit)

	var t = true
	var i = 1
	fmt.Println(t, i)
	i, j, k := 3, 4, 5
	//i, j, k := 3, 4, 5  //no new variables on left side of :=
	fmt.Println(i, j, k)

	f := "fuck"
	fmt.Println(f)
	//g = "gg"
	var (
		x int  = 1024
		y bool = true
	)

	fmt.Println(x, y)

	//var z byte  //不接受未使用的局部变量， 全局变量可以不使用
	r, s, o := 'a', "b", 0xc //可以自动推断类型，但是类型定下来之后无法再改变, 全局变量无法这样使用

	fmt.Println(r, s, o)

	buf := "hello"
	buf = "world"
	fmt.Println(buf)

	const PI float64 = 3.141592653
	const NAME = "Trump"

	//PI = 2                     //常量不能修改。 常量可以不使用
	//NAME = "WTF"
	const (
		Unknown = 0 //枚举，第一个值必须给定, 后面的值不确定则与前面最近的值相同
		Female  = 1
		Male
		T = "abc"
		F
	)
	fmt.Println(Unknown, Female, Male, T, F)

	const (
		u = "wtf nimabisssssssssssssssss"
		v = len(u)
		w = unsafe.Sizeof(u)
	)
	fmt.Println(u, v, w)

	//var i8 int8
	fmt.Println(unsafe.Sizeof(x))

	const (
		zero = iota
		one
		two
		three = "wtf"
		four         //equal three
		five  = iota //恢复递增
		six
	)
	fmt.Println(zero, one, two, three, four, five, six)

	const (
		mul0 = 0 * iota
		mul1 = 1 * iota
		mul2 = 2 * iota //wtf
		mul3            //2*3
		mul4            //2*4
		mul5            //2*5
	)
	fmt.Println(mul0, mul1, mul2, mul3, mul4, mul5)

	const (
		c0 = 0
		c1
		c2 = iota
		c3
		c4
	)
	fmt.Println(c0, c1, c2, c3, c4)
	var ir int32 = -1
	var ur uint32 = 0xFFFFFFFF

	fmt.Println(ir >> 1)
	fmt.Println(ur >> 1)

	var i8r int8 = -1
	fmt.Println(i8r << 7)

	var addrTest int
	var ptr *int = &addrTest

	fmt.Println(ptr)
	fmt.Println(*ptr)
	*ptr = 5201314
	fmt.Println(*ptr, addrTest)
	addrTest++
	//--addrTest //syntax error: unexpected --, expecting } Go 没有前++和前--操作
	i = addrTest
	//var i64 int64 = addrTest
	if i < 20 { //Go 判断语句可以不加（）
		fmt.Println("i < 20")
	} else {
		fmt.Println("zz")
	}

	if i != 0 && i > 20 {
		fmt.Println("i != 0 && i > 20")
	} else if i < 9 {
		fmt.Println(i)
	}

	/*
		if 1 {
			fmt.Println("if 1 is true")
		}
	*/

	//条件语句与C 不同的地方就是可以不要（）, 没有非0即真

	switchTest(4)
	typeSwitchTest()

	sum := 1
	for sum <= 10 {
		sum += sum
	}
	fmt.Println(sum)
	/*
		for {
			fmt.Println("Dead loop")
		}
	*/
	array := []int{0, 5, 2, 6, 1, 6, 25, 9}
	for idx, val := range array {
		fmt.Println(idx, val)
	}
	var n [10]int
	for i := 0; i < len(n); i++ {
		n[i] = 1 << i
	}
	fmt.Println("i = ", i)

	for idx, val := range n {
		fmt.Println(idx, val)
	}

	var wtf = [5]int{1, 2, 3, 4, 5}
	wtf = [5]int{2, 3, 5, 2, 6}
	sliceFuncTest(wtf[:])

	var fuck = [5]int{2}
	fuck[4] = 99
	//wtf[7] = 999 //runtime error 运行时错误
	fmt.Println("176:", arrayFuncTest(wtf))
	fmt.Println("177:", wtf)
	fmt.Println("WTF test ", wtf[4])

	var twoDim = [][]int{
		{1, 2, 3, 4, 7},
		{4, 5},
	}

	fmt.Println(twoDim[0][2], twoDim[1][1])
	fmt.Println(twoDim, twoDim[0], twoDim[1])
	fmt.Println(unsafe.Sizeof(twoDim), unsafe.Sizeof(twoDim[0]), unsafe.Sizeof(twoDim[1]))
	fmt.Println(len(twoDim), len(twoDim[0]), len(twoDim[1]))

	arrayFuncTest([5]int{1, 2, 3, 4})

	slice := []int{1, 2, 3}
	sliceFuncTest(slice)
	fmt.Println(slice[0])

	sa, sb := 1, -1
	fmt.Println(sa, sb)
	sa, sb = sb, sa
	fmt.Println(sa, sb)

	var aa int
	var paa *int = &aa
	fmt.Printf("&aa = %x\n", &aa)
	fmt.Printf("paa = %x\n", paa)
	fmt.Printf("&paa = %x\n", &paa)

	const ca int = 5201024
	//fmt.Printf("&ca = %x\n", &ca)  常量无法取地址
	var pt *int
	fmt.Println(pt)
	fmt.Printf("%e\n", float32(1))

	arrT3 := [3]int{0, 1, 2}
	arrT3p := [3]*int{&arrT3[2], &arrT3[0], &arrT3[1]}
	fmt.Println(*arrT3p[0], *arrT3p[1], *arrT3p[2])

	//parrT3 := &arrT3
	arrayPtrTest(&arrT3)
	fmt.Println(arrT3[0])

}

func arrayPtrTest(arrPtr *[3]int) int {

	fmt.Println(arrPtr[1])
	arrPtr[0] = 012345
	fmt.Println(arrPtr[0])
	return len(*arrPtr)
}

func sliceFuncTest(slice []int) int {
	slice[0] = 888
	return len(slice)
}

func arrayFuncTest(n [5]int) int {

	fmt.Println(n[4])
	n[4] = 012345
	fmt.Println(n[4])
	return len(n)
}

func switchTest(x int) {
	//switch ,case 不加break，不会掉入下面的case
	//要掉入下面的case得加上fallthrough
	//某些情况不想掉入下面的case可以用break打断
	switch x {
	case 1, 2, 3, 4:
		fmt.Println(x)
		break
		fallthrough
	default:
		fmt.Println("Other:", x)
	}
}

func typeSwitchTest() {
	var x interface{}
	//var x int8
	switch i := x.(type) {
	default:
		fmt.Printf("type is %T\n", i)
	}

	switch {
	case false:
		fmt.Println("1.false")
	case true:
		fmt.Println("2.true")
	}
}

func selectTest() {
	//TODO
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
