package demo

import "testing"

func TestSum(t *testing.T) {
	s := Sum(100)
	if s != 5050 {
		t.Error("Failed")
	}
}

func BenchmarkSum(t *testing.B) {
	for i := 0; i < t.N; i++ {
		Sum(100)
	}
}
