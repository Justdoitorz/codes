

func twoSum(nums []int, target int) []int {
	m := make(map[int]int, len(nums))

	for k, v := range nums {
		if i, ok := m[v]; ok {
			return []int{i, k}
		} else {
			m[target-v] = k
		}
	}
	return []int{}
}