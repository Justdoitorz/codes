package main

import (
	"errors"
	"fmt"
	"math"
	"time"

	"./subdir"
)

//Books is a bitch
type Books struct {
	title   string
	author  string
	subject string
	bookID  int
}

func main() {
	fmt.Println("Struct test")
	var hary Books
	fmt.Println(hary)
	//otherTest()

	fmt.Println(float32(1))
	var i8 int8 = 33 //编译时检测溢出无法通过编译
	var i32 int32 = 255
	i8 = int8(i32)
	fmt.Println(i8, i32)

	array := [10]int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Println(len(array), cap(array))
	slice := array[2:]
	fmt.Println(slice)
	slice[1] = 111
	fmt.Println(array)
	fmt.Println(slice)

	slice = make([]int, 6, 7)
	fmt.Println(slice)
	fmt.Println(len(slice), cap(slice))
	tmp := slice
	slice = append(slice, 99)
	slice[0] = 1024
	fmt.Println(slice)
	fmt.Println(tmp)
	fmt.Println(len(tmp), cap(tmp))
	slice = append(slice, 8)
	slice[1] = 2
	fmt.Println(slice)
	fmt.Println(tmp)

	fmt.Println(len(tmp), cap(tmp))

	interfaceTest()
	errorTest()
	subdir.OtherTest()
	go say("Bitch", 500)
	say("WTF", 1000)

}

//Phone is machine
type Phone interface {
	call(string) string
}

//NokiaPhone is a zhuangtou
type NokiaPhone struct {
}

func (nokiaPhone *NokiaPhone) call(mess string) string {
	fmt.Println("I am NokiaPhone,", mess)
	return "NokiaPhone"
}

//IPhone is a apple
type IPhone struct {
}

func (iPhone IPhone) call(mess string) string {
	fmt.Println("I am IPhone,", mess)
	return "IPhone"
}

func interfaceTest() {
	fmt.Println("------------------- interfaceTest: begin --------------------")
	var phone Phone

	//phone.call("wtf")
	//var nokiaPhone NokiaPhone
	//phone = nokiaPhone
	//phone.call("Fuck")
	phone = new(NokiaPhone)
	phone.call("It's so hard")

	phone = new(IPhone)
	phone.call("It's so expensive")

	fmt.Println("------------------- interfaceTest:  end  --------------------")
}

func errorTest() {
	fmt.Println("------------------- errorTest: begin --------------------")
	if result, err := Sqrt(5); err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(result)
	}
	fmt.Println("------------------- errorTest:  end  --------------------")
}

//Sqrt ...
func Sqrt(f float64) (float64, error) {
	if f < 0 {
		return 0, errors.New("math: square root of negative number")
	}
	l, m, r := 0.0, f/2, f
	for math.Abs(m*m-f) > 1e-8 {
		if m*m > f {
			m, r = (l+m)/2, m
		} else if m*m < f {
			l, m = m, (m+r)/2
		}
	}
	return m, nil
}

func say(mess string, dly time.Duration) {
	for i := 0; i < 5; i++ {
		time.Sleep(dly * time.Millisecond)
		fmt.Println(mess)
	}
	fmt.Println(dly.String())
}
