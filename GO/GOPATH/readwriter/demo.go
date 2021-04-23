package main

import (
	"bufio"
	"bytes"
	"fmt"
)

func main() {
	data := []byte("I love you, 傻逼")
	rd := bytes.NewReader(data)
	r := bufio.NewReader(rd)
	var buf [128]byte
	c, err := r.ReadByte()
	fmt.Println(string(c), err)

	line, err := r.ReadBytes('o')
	fmt.Println(string(line), err)

	n, err := r.Read(buf[:])
	fmt.Println(string(buf[:n]), n, err)
}
