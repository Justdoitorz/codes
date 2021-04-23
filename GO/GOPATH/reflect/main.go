package main

import (
	"fmt"
	"reflect"

	"github.com/codegangsta/inject"
)

//Enum ..
type Enum int

const (
	//Zero ..
	Zero Enum = 0
)

func main() {
	var a int

	typeOfA := reflect.TypeOf(a)
	aIns := reflect.New(typeOfA)
	fmt.Println(aIns.Type(), aIns.Kind())

	fmt.Println(typeOfA.Name(), typeOfA.Kind())

	type cat struct {
		name  string
		Ttype int `json:"type" id:"100"`
	}
	type pcat *cat

	typeOfCat := reflect.TypeOf(cat{})
	fmt.Println(typeOfCat.Name(), typeOfCat.Kind())

	typeOfZero := reflect.TypeOf(Zero)
	fmt.Println(typeOfZero.Name(), typeOfZero.Kind())

	p := cat{
		name:  "mimi",
		Ttype: 1,
	}
	typeOfPcat := reflect.TypeOf(p)
	fmt.Println(typeOfPcat.Name(), typeOfPcat.Kind())

	for i := 0; i < typeOfPcat.NumField(); i++ {
		fieldType := typeOfPcat.Field(i)

		fmt.Printf("name: %v tag: '%v'\n", fieldType.Name, fieldType.Tag)
	}

	if catType, ok := typeOfPcat.FieldByName("Ttype"); ok {
		fmt.Println(catType.Tag.Get("json"), catType.Tag.Get("id"))
	}

	//typeOfPcat = typeOfPcat.Elem()
	//fmt.Println(typeOfPcat.Name(), typeOfPcat.Kind())

	var a2 int = 1024
	valueOfA := reflect.ValueOf(a2)

	var getA int = valueOfA.Interface().(int)
	var getA2 int = int(valueOfA.Int())

	fmt.Println(getA, getA2)

	d := reflect.ValueOf(dummy{
		next: &dummy{
			next: &dummy{},
		},
	})

	fmt.Println("NumField", d.NumField())
	floatField := d.Field(2)
	fmt.Println("Field", floatField.Type())

	fmt.Println("FieldByName(\"b\").Type()", d.FieldByName("b").Type())
	fmt.Println("FieldByIndex([]int{4, 0}).Type()", d.FieldByIndex([]int{4, 4, 3}).Type())

	var p2 *int
	var p3 **int = &p2
	*p3 = &a
	**p3 = 1235436
	fmt.Println("var p2 *int:", reflect.ValueOf(p2).IsNil())

	fmt.Println("(*int)(nil):", reflect.ValueOf((*int)(nil)).Elem().IsValid())

	s := struct{}{}
	fmt.Println("不存在的结构体成员:", reflect.ValueOf(s).FieldByName("").IsValid())
	fmt.Println("不存在的结构体方法:", reflect.ValueOf(s).MethodByName("").IsValid())

	m := map[int]int{}
	//m[3] = 2
	fmt.Println("不存在的键：", reflect.ValueOf(m).MapIndex(reflect.ValueOf(3)).IsValid())

	funcValue := reflect.ValueOf(add)
	paramList := []reflect.Value{reflect.ValueOf(10), reflect.ValueOf(20)}

	reqList := funcValue.Call(paramList)
	fmt.Println(reqList[0].Int())

	inj := inject.New()

	inj.Map("Tom")
	inj.MapTo("Tencent", (*S1)(nil))
	inj.MapTo("T4", (*S2)(nil))
	inj.Map(23)

	inj.Invoke(Format)

	st := Staff{}

	injs := inject.New()
	injs.Map("Tom")
	injs.MapTo("Tencent", (*S1)(nil))
	injs.MapTo("T4", (*S2)(nil))
	injs.Map(99)

	injs.Apply(&st)

	fmt.Println(st)

	inj.Apply(&st)
	fmt.Println(st)
}

type dummy struct {
	a int
	b string
	float32
	bool
	next *dummy
}

func add(a, b int) int {
	return a + b
}

//S1 ...S1
type S1 interface{}

//S2 ...
type S2 interface{}

//Format ...
func Format(name string, company S1, level S2, age int) {
	fmt.Printf("name = %s, commpany = %s, level = %s, age = %d\n", name, company, level, age)
}

//Staff ...
type Staff struct {
	Name    string `inject:"Name"`
	Company S1     `inject:"Company"`
	Level   S2     `inject:"Level"`
	Age     int    `inject:"Age"`
}
