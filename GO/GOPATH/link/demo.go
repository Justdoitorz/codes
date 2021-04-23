package main

import "fmt"

type node struct {
	next *node
	data int
}

func showNode(p *node) {
	for p != nil {
		fmt.Println(*p)
		p = p.next
	}
}

type father struct {
	Type string
}

type son struct {
	father
	Type string
}

func (f *father) showType() {
	fmt.Println(f.Type)
}
func (s *son) showType() {
	fmt.Println(s.Type)
}

func insertNodeHead(head *node, n *node) *node {
	n.next = head
	return n
}

func insertNodeTail(tail *node, n *node) *node {
	tail.next = n
	return n
}
func main() {
	var head = new(node)
	head.data = 1

	node1 := new(node)
	node1.data = 2

	head = insertNodeHead(head, node1)

	node2 := new(node)
	node2.data = 3

	head = insertNodeHead(head, node2)

	tail := insertNodeTail(node1.next, &node{
		data: 4,
	})

	tail = insertNodeTail(tail, &node{
		data: 5,
	})

	showNode(head)

	var f = &father{
		"person",
	}

	var s = &son{
		*f,
		"Sharen",
	}

	f.showType()
	fmt.Println(s)
	s.showType()
	fmt.Println(s.Type)
}
