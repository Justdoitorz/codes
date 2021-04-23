package main

import (
	"encoding/xml"
	"fmt"
	"os"
)

type Website struct {
	Name   string `xml:"name,attr"`
	Url    string
	Course []string
}

func mainb() {
	info := Website{"C语言中文网", "http://c.biancheng.net/golang/", []string{"Go语言入门教程", "Golang入门教程"}}
	file, err := os.Create("info.xml")
	if err != nil {
		fmt.Println("Create failed", err.Error())
		return
	}
	defer file.Close()

	err = xml.NewEncoder(file).Encode(info)
	if err != nil {
		fmt.Println("Encoder failed", err.Error())
	} else {
		fmt.Println("Encoder success")
	}
}
