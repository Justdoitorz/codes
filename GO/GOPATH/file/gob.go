package main

import (
	"encoding/gob"
	"fmt"
	"os"
)

func main() {
	fmt.Println("Gob")
	info := map[string]string{
		"Name": "Jsten",
		"Date": "20200628",
	}
	fmt.Println(info)

	file, _ := os.OpenFile("gob.gob", os.O_RDWR|os.O_CREATE, 0777)
	defer file.Close()

	enc := gob.NewEncoder(file)
	if err := enc.Encode(info); err != nil {
		fmt.Println(err)
	}

	var m map[string]string
	fr, _ := os.Open("gob.gob")
	dec := gob.NewDecoder(fr)
	dec.Decode(&m)
	fmt.Println(m)
}
