package date

func bool2int(b bool) int {
	if b {
		return 1
	}
	return 0
}

func int2bool(i int) bool {
	return i != 0
}

func xor(a, b bool) bool {
	return a != b
}

func isLeapYear(year int) bool {
	if year%4 != 0 || year%100 == 0 && year%400 != 0 {
		return false
	}
	return true
}

func getDaysByYYMM(YY, MM int) int {
	if MM != 2 {
		return 30 + (bool2int(MM > 7) ^ (MM & 1))
	}
	return 28 + bool2int(isLeapYear(YY))
}