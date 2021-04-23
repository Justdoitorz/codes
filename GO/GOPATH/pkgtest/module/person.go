package module

import "fmt"

type person struct {
	Name string
	age  int
	sal  float64
}

//NewPerson ..
func NewPerson(name string) *person {
	return &person{
		Name: name,
	}
}

func (p *person) SetAge(age int) {
	if age > 0 && age < 150 {
		p.age = age
	} else {
		fmt.Println("age errors")
	}
}

func (p *person) GetAge() int {
	return p.age
}

func (p *person) SetSal(sal float64) {
	if sal >= 3000 && sal <= 30000 {
		p.sal = sal
	} else {
		fmt.Println("sal errors")
	}
}

func (p *person) GetSal() float64 {
	return p.sal
}

func (p *person) getSal() float64 {
	return p.sal
}
